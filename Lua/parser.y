%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%define api.token.constructor

%verbose

%define parse.trace

%define parse.error verbose

%code requires
{
#include "globals.h"
#include "variable.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
}
%code{
    #include <iostream>
	#include <vector>
	#include <map>
	#include <algorithm>
    #define YY_DECL yy::parser::symbol_type yylex()

    YY_DECL;
	
	using namespace rapidjson;
	using namespace std;

	Document *root;
	Table t;
}

%type <rapidjson::Document *> program
%type <rapidjson::Document *> block
%type <std::vector<rapidjson::Document *>> opstat
%type <rapidjson::Document *> stat
%type <rapidjson::Document *> forstep
%type <std::vector<rapidjson::Document *>> eqexplist
%type <rapidjson::Document *> else
%type <rapidjson::Document *> elseif
%type <std::vector<rapidjson::Document *>> elseifs
%type <rapidjson::Document *> retstat
%type <std::vector<rapidjson::Document *>> opexplist
%type <std::string> opsemicolon
%type <rapidjson::Document *> funcname
%type <std::vector<std::string>> dotnames
%type <std::string> colonname
%type <std::vector<rapidjson::Document *>> varlist
%type <std::vector<rapidjson::Document *>> commavar
%type <rapidjson::Document *> var
%type <std::vector<std::string>> namelist
%type <std::vector<std::string>> commanames
%type <std::vector<rapidjson::Document *>> explist
%type <std::vector<rapidjson::Document *>> commaexps
%type <rapidjson::Document *> exp
%type <rapidjson::Document *> prefixexp
%type <rapidjson::Document *> functioncall
%type <rapidjson::Document *> args
%type <rapidjson::Document *> functiondef
%type <rapidjson::Document *> funcbody
%type <rapidjson::Document *> parlist
%type <bool> opcommadots
%type <rapidjson::Document *> tableconstructor
%type <rapidjson::Document *> fieldlist
%type <std::vector<rapidjson::Document *>> opsepfields
%type <std::string> opsep
%type <rapidjson::Document *> field
%type <std::string> fieldsep

%token <std::string> TK_NAME

%token <std::string> TK_BREAK
%token <std::string> TK_DO
%token <std::string> TK_ELSE
%token <std::string> TK_ELSEIF
%token <std::string> TK_END
%token <std::string> TK_FALSE
%token <std::string> TK_FOR
%token <std::string> TK_FUNCTION
%token <std::string> TK_IF
%token <std::string> TK_IN
%token <std::string> TK_LOCAL
%token <std::string> TK_NIL

%token <std::string> TK_REPEAT
%token <std::string> TK_RETURN
%token <std::string> TK_THEN
%token <std::string> TK_TRUE
%token <std::string> TK_UNTIL
%token <std::string> TK_WHILE
%token <std::string> TK_DOTS

%token <double> TK_NUMBER

%token <std::string> TK_STRING
%token <std::string> TK_WHITESPACE
%token <std::string> TK_BADCHAR
%token <std::string> TK_SEMICOLON
%token <std::string> TK_COLON
%token <std::string> TK_UEQ
%token <std::string> TK_LB
%token <std::string> TK_RB
%token <std::string> TK_LKB
%token <std::string> TK_RKB
%token <std::string> TK_LFB
%token <std::string> TK_RFB
%token <std::string> TK_COMMA
%token <std::string> TK_DOT

%token QUIT 0 "end of file"

%left <std::string> TK_OR
%left <std::string> TK_AND
%left <std::string> TK_LT TK_GR TK_GE TK_LE TK_EQ TK_NE
%left <std::string> TK_CONCAT
%left <std::string> TK_PLUS TK_MINUS
%left <std::string> TK_MUL TK_DIV TK_PREC
%left <std::string> TK_CARET
%left <std::string> TK_NOT TK_HASH
%left UMINUS

%%

program	: block 
		{
			$$ = $1;
			root = $$;
		}
		| 
		{
			$$ = new Document();
			$$->SetObject();
			root = $$;
		}
		;

block	: {t.add_level();}
		  opstat retstat
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			reverse($2.begin(), $2.end());

			Document doc;
			auto& alloc = doc.GetAllocator();
			doc.SetArray();
			for (Document *d : $2)
				if (d->IsArray())
					for (SizeType i = 0; i < d->Size(); i++)
						doc.PushBack((*d)[i], alloc);
				else
					doc.PushBack(*d, alloc);

			json_val.CopyFrom(doc, allocator);
			$$->AddMember("states", json_val, allocator);
			if (!$3->ObjectEmpty())
			{
				json_val.CopyFrom(*$3, allocator); 
				$$->AddMember("retstat", json_val, allocator);
			}
			t.delete_level();
		}
		;
		
opstat	: stat opstat
		{
			$$ = $2;
			$$.push_back($1);
		}
		|
		TK_SEMICOLON opstat
		{
			$$ = $2;
		}
		| {$$ = vector<Document *>();}
		;

stat	: varlist TK_UEQ explist
		{
			$$ = new Document();
			$$->SetArray();
			auto& alloc = $$->GetAllocator();
			reverse($1.begin(), $1.end());
			reverse($3.begin(), $3.end());
			for (int i = 0; i< min($1.size(), $3.size()); i++)
			{
				Document *d = new Document();
				d->SetObject();
				auto& allocator = d->GetAllocator();
				Value json_val;
				
				bool var = (*$1[i]).FindMember("var_name") == (*$1[i]).MemberEnd() ? false : true;
				if (var)
				{
					json_val.SetString((*$1[i])["var_name"].GetString(), allocator);
					d->AddMember("variable_name", json_val, allocator);
					json_val.SetString((*$3[i])["type"].GetString(), allocator);
					d->AddMember("type", json_val, allocator);
					json_val.SetUint64(t.add((*$1[i])["var_name"].GetString(), (*$3[i])["type"].GetString()));
					d->AddMember("id", json_val, allocator);
				} else
				{
					json_val.CopyFrom(*$1[i], allocator);
					d->AddMember("variable", json_val, allocator);
				}
				
				json_val.CopyFrom(*$3[i], allocator);
				d->AddMember("expression", json_val, allocator);
				
				Document *assigment = new Document();
				assigment->SetObject();
				auto& asg_allocator = assigment->GetAllocator();
				Value asg_json_val;
				asg_json_val.CopyFrom(*d, asg_allocator);
				assigment->AddMember("assigment", asg_json_val, asg_allocator);

				$$->PushBack(*assigment, alloc);
			}
			for (int i =  $3.size(); i < $1.size(); i++)
			{
				Document *d = new Document();
				d->SetObject();
				auto& allocator = d->GetAllocator();
				Value json_val;

				bool var = (*$1[i]).FindMember("var_name") == (*$1[i]).MemberEnd() ? false : true;
				if (var)
				{
					json_val.SetString((*$1[i])["var_name"].GetString(), allocator);
					d->AddMember("variable_name", json_val, allocator);
					json_val.SetString("nil", allocator);
					d->AddMember("type", json_val, allocator);
					json_val.SetUint64(t.add((*$1[i])["var_name"].GetString(), "nil"));
					d->AddMember("id", json_val, allocator);
				} else
				{
					json_val.CopyFrom(*$1[i], allocator);
					d->AddMember("variable", json_val, allocator);
				}
				
				Document *assigment = new Document();
				assigment->SetObject();
				auto& asg_allocator = assigment->GetAllocator();
				Value asg_json_val;
				asg_json_val.CopyFrom(*d, asg_allocator);
				assigment->AddMember("assigment", asg_json_val, asg_allocator);

				$$->PushBack(*assigment, alloc);
			}
		}
		|
		functioncall
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$1, allocator);
			$$->AddMember("functioncall", json_val, allocator);
		}
		|
		TK_DO block TK_END
		{
			$$ = $2;
		}
		|
		TK_WHILE exp TK_DO block TK_END
		{
			$$ = new Document();
			$$->SetObject();
			auto& allocator = $$->GetAllocator();

			Document *whl = new Document();
			whl->SetObject();
			auto& whl_allocator = whl->GetAllocator();
			Value json_val;
			json_val.CopyFrom(*$2, whl_allocator);
			whl->AddMember("condition", json_val, whl_allocator);
			json_val.CopyFrom(*$4, whl_allocator);
			whl->AddMember("block", json_val, whl_allocator);

			json_val.CopyFrom(*whl, allocator);
			$$->AddMember("while", json_val, allocator);
		}
		|
		TK_REPEAT block TK_UNTIL exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();

			Document *rpt = new Document();
			rpt->SetObject();
			auto& rpt_allocator = rpt->GetAllocator();
			json_val.CopyFrom(*$4, rpt_allocator);
			rpt->AddMember("condition", json_val, rpt_allocator);
			json_val.CopyFrom(*$2, rpt_allocator);
			rpt->AddMember("block", json_val, rpt_allocator);

			json_val.CopyFrom(*rpt, allocator);
			$$->AddMember("repeat", json_val, allocator);
		}
		|
		TK_IF exp TK_THEN block elseifs else TK_END
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();

			Document *ifd = new Document();
			ifd->SetObject();
			auto& if_allocator = ifd->GetAllocator();
			json_val.CopyFrom(*$2, if_allocator);
			ifd->AddMember("condition", json_val, if_allocator);
			json_val.CopyFrom(*$4, if_allocator);
			ifd->AddMember("then", json_val, if_allocator);
			reverse($5.begin(), $5.end());
			if ($5.size()>0)
			{
				Document *elseifs = new Document();
				elseifs->SetArray();
				auto& elseifs_allocator = elseifs->GetAllocator();
				for (Document *d : $5)
					elseifs->PushBack(*d, elseifs_allocator);
				json_val.CopyFrom(*elseifs, if_allocator);
				ifd->AddMember("elseifs", json_val, if_allocator);
			}

			if (!$6->ObjectEmpty())
			{
				json_val.CopyFrom(*$6, if_allocator);
				ifd->AddMember("else", json_val, if_allocator);
			}
			json_val.CopyFrom(*ifd, allocator);
			$$->AddMember("if", json_val, allocator);
		}
		|
		TK_FOR TK_NAME TK_UEQ exp TK_COMMA exp forstep
		{
			t.add_level();

			string t1 = (*$4)["type"].GetString();
			string t2 = (*$6)["type"].GetString();
			string t3 = (*$7)["type"].GetString();
			string tp;
			if (t1 == "double" && t2 == "double" && t3 == "double")
				tp = "double";
			else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown") && (t3 == "string" || t3 == "double" || t3 == "unknown"))
				tp = "unknown";
			else
				tp = "error";
			t.add_local($2, tp);		
		}
		TK_DO block TK_END
		{		
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			
			Document *ford = new Document();
			ford->SetObject();
			auto& for_allocator = ford->GetAllocator();
			
			json_val.SetString($2.c_str(), for_allocator);
			ford->AddMember("control_variable_name", json_val, for_allocator);
			
			pair<unsigned long long, string> p = t.get($2);

			json_val.SetString(p.second.c_str(), for_allocator);
			ford->AddMember("type", json_val, for_allocator);
			json_val.SetUint64(p.first);
			ford->AddMember("control_variable_id", json_val, for_allocator);
			json_val.CopyFrom(*$4, for_allocator);
			ford->AddMember("begin", json_val, for_allocator);
			json_val.CopyFrom(*$6, for_allocator);
			ford->AddMember("end", json_val, for_allocator);
			json_val.CopyFrom(*$7, for_allocator);
			ford->AddMember("step", json_val, for_allocator);
			json_val.CopyFrom(*$10, for_allocator);
			ford->AddMember("block", json_val, for_allocator);
			
			json_val.CopyFrom(*ford, allocator);
			$$->AddMember("for", json_val, allocator);

			t.delete_level();
		}
		|
		TK_FOR namelist TK_IN explist 
		{
			t.add_level();
			for(string s : $2)
				t.add_local(s, "unknown");
		}
		TK_DO block TK_END
		{
			$$ = new Document();
			$$->SetObject();
			auto& allocator = $$->GetAllocator();

			reverse($4.begin(), $4.end());

			Document d;
			d.SetArray();
			auto& alloc = d.GetAllocator();
			Value json_val;

			for(string s : $2)
			{
				Document *v = new Document();
				v->SetObject();
				auto& alc = v->GetAllocator();
				Value jv;
				jv.SetString(s.c_str(), alc);
				v->AddMember("variable_name", jv, alc);
				jv.SetString("unknown", alc);
				v->AddMember("type", jv, alc);
				jv.SetUint64(t.get(s).first);
				v->AddMember("id", jv, alc);
				d.PushBack(*v, alloc);
			}
			Document *ford = new Document();
			ford->SetObject();
			auto& for_allocator = ford->GetAllocator();

			json_val.CopyFrom(d, for_allocator);
			ford->AddMember("name_list", json_val, for_allocator);
			Document de;
			de.SetArray();
			auto& alloce = de.GetAllocator();
			for(Document *e : $4)
				de.PushBack(*e, alloce);
			json_val.CopyFrom(de, for_allocator);
			ford->AddMember("expressions_list", json_val, for_allocator);
			json_val.CopyFrom(*$7, for_allocator);
			ford->AddMember("block", json_val, for_allocator);

			json_val.CopyFrom(*ford, allocator);
			$$->AddMember("foreach", json_val, allocator);

			t.delete_level();
		}
		|
		TK_FUNCTION funcname funcbody
		{
			$$ = new Document();
			$$->SetObject();
			auto& allocator = $$->GetAllocator();
			Value json_val;

			Document *fd = new Document();
			fd->SetObject();
			auto& f_allocator = fd->GetAllocator();

			json_val.CopyFrom(*$2, f_allocator);
			fd->AddMember("name", json_val, f_allocator);
			json_val.CopyFrom(*$3, f_allocator);
			fd->AddMember("body", json_val, f_allocator);

			json_val.CopyFrom(*fd, allocator);
			$$->AddMember("function_definition", json_val, allocator);
		}
		|
		TK_LOCAL TK_FUNCTION TK_NAME funcbody
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();

			Document *fd = new Document();
			fd->SetObject();
			auto& f_allocator = fd->GetAllocator();

			json_val.SetString($3.c_str(), f_allocator);
			fd->AddMember("name", json_val, f_allocator);
			json_val.CopyFrom(*$4, f_allocator);
			fd->AddMember("body", json_val, f_allocator);

			json_val.CopyFrom(*fd, allocator);
			$$->AddMember("local_function_definition", json_val, allocator);
		}
		|
		TK_LOCAL namelist eqexplist
		{
			$$ = new Document();
			$$->SetArray();
			auto& alloc = $$->GetAllocator();
			
			for (int i = 0; i< min($2.size(), $3.size()); i++)
			{
				Document *d = new Document();
				d->SetObject();
				auto& allocator = d->GetAllocator();
				Value json_val;
				
				json_val.SetString($2[i].c_str(), allocator);
				d->AddMember("variable_name", json_val, allocator);
				json_val.SetString((*$3[i])["type"].GetString(), allocator);
				d->AddMember("type", json_val, allocator);
				json_val.SetUint64(t.add_local($2[i], (*$3[i])["type"].GetString()));
				d->AddMember("id", json_val, allocator);
				json_val.CopyFrom(*$3[i], allocator);
				d->AddMember("expression", json_val, allocator);
				Document *assigment = new Document();
				assigment->SetObject();
				auto& asg_allocator = assigment->GetAllocator();
				Value asg_json_val;
				asg_json_val.CopyFrom(*d, asg_allocator);
				assigment->AddMember("assigment", asg_json_val, asg_allocator);

				$$->PushBack(*assigment, alloc);
			}
			for (int i = $3.size(); i < $2.size(); i++)
			{
				Document *d = new Document();
				d->SetObject();
				auto& allocator = d->GetAllocator();
				Value json_val;
				json_val.SetString($2[i].c_str(), allocator);
				d->AddMember("variable_name", json_val, allocator);
				json_val.SetString("nil", allocator);
				d->AddMember("type", json_val, allocator);
				json_val.SetUint64(t.add_local($2[i], "nil"));
				d->AddMember("id", json_val, allocator);
				Document *assigment = new Document();
				assigment->SetObject();
				auto& asg_allocator = assigment->GetAllocator();
				Value asg_json_val;
				asg_json_val.CopyFrom(*d, asg_allocator);
				assigment->AddMember("assigment", asg_json_val, asg_allocator);

				$$->PushBack(*assigment, alloc);
			}
		}
		;

forstep	: TK_COMMA exp
		{
			$$ = $2;
		}
		|
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetDouble(1);
			$$->AddMember("value", json_val, allocator);
			json_val.SetString("double", allocator);
			$$->AddMember("type", json_val, allocator);
		}
		;

eqexplist: TK_UEQ explist
		{
			reverse($2.begin(), $2.end());
			$$ = $2;
		}
		| {$$ = vector<Document *>();}
		;

elseif	: TK_ELSEIF exp TK_THEN block
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$2, allocator);
			$$->AddMember("condition", json_val, allocator);
			json_val.CopyFrom(*$4, allocator);
			$$->AddMember("then", json_val, allocator);
		}
		;

elseifs	: elseif elseifs
		{
			$$ = $2;
			if (!$1->ObjectEmpty())
				$$.push_back($1);
		}
		|
		{$$ = vector<Document *>();}
		;	
		
else	: TK_ELSE block
		{
			$$ = $2;
		}
		|
		{
			$$ = new Document();
			$$->SetObject();
		}
		;

retstat	: TK_RETURN opexplist opsemicolon
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			Document doc;
			doc.SetArray();
			auto& alloc = doc.GetAllocator();
			for (Document *d : $2)
				doc.PushBack(*d, alloc);
			json_val.CopyFrom(doc, allocator);
			$$->AddMember("return_expressions", json_val, allocator);
		}
		|
		TK_BREAK opsemicolon
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetString($1.c_str(), allocator); 
			$$->AddMember("break", json_val, allocator);
		}
		|
		{
			$$ = new Document();
			$$->SetObject();
		}
		;
		
opexplist: explist
		{
			reverse($1.begin(), $1.end());
			$$=$1;
		}
		|
		{$$ = vector<Document *>();}
		;
		
opsemicolon: TK_SEMICOLON
		| {$$ = "";}
		;

funcname: TK_NAME dotnames colonname
		{
			$$ = new Document();
			$$->SetObject();
			auto& allocator = $$->GetAllocator();
			Document d;
			auto& alloc = d.GetAllocator();
			d.SetArray();
			d.PushBack(Value($1.c_str(), alloc).Move(), alloc);
			reverse($2.begin(), $2.end());
			Value json_val;
			for (string s : $2)
				d.PushBack(Value(s.c_str(), alloc).Move(), alloc);
			if ($3 != "")
			{
				d.PushBack(Value($3.c_str(), alloc).Move(), alloc);
				json_val.SetBool(true); 
			}
			else
			{
				json_val.SetBool(false); 
			}
			$$->AddMember("self_argument", json_val, allocator);
			json_val.CopyFrom(d, allocator); 
			$$->AddMember("function_name", json_val, allocator);
		}
		;

dotnames: TK_DOT TK_NAME dotnames
		{
			$$ = $3;
			$$.push_back($2);
		}
		| {$$ = vector<string>();}
		;

colonname: TK_COLON TK_NAME
		{
			$$ = $2;
		}
		| {$$ = "";}
		;
		
varlist	: var commavar
		{
			$$ = $2;
			$$.push_back($1);
		}
		;
		
commavar: TK_COMMA varlist
		{
			$$ = $2;
		}
		| {$$ = vector<Document *>();}
		;

var		: TK_NAME
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetString($1.c_str(), allocator); 
			$$->AddMember("var_name", json_val, allocator);
		}
		|
		var TK_LKB exp TK_RKB
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("prefix_expression", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("index", json_val, allocator);
		}
		|
		functioncall TK_LKB exp TK_RKB
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("prefix_expression", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("index", json_val, allocator);
		}
		|
		TK_LB exp TK_RB TK_LKB exp TK_RKB
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$2, allocator); 
			$$->AddMember("prefix_expression", json_val, allocator);
			json_val.CopyFrom(*$5, allocator); 
			$$->AddMember("index", json_val, allocator);
		}
		|
		var TK_DOT TK_NAME
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("prefix_expression", json_val, allocator);
			json_val.SetString($3.c_str(), allocator); 
			$$->AddMember("name", json_val, allocator);
		}
		|
		functioncall TK_DOT TK_NAME
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("prefix_expression", json_val, allocator);
			json_val.SetString($3.c_str(), allocator); 
			$$->AddMember("name", json_val, allocator);
		}
		|
		TK_LB exp TK_RB TK_DOT TK_NAME
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$2, allocator); 
			$$->AddMember("prefix_expression", json_val, allocator);
			json_val.SetString($5.c_str(), allocator); 
			$$->AddMember("name", json_val, allocator);
		}
		;
		
namelist: TK_NAME commanames
		{
			$$ = $2;
			$$.push_back($1);
			reverse($$.begin(), $$.end());
		}
		;
		
commanames: TK_COMMA TK_NAME commanames
		{
			$$ = $3;
			$$.push_back($2);
		}
		| {$$ = vector<string>();}
		;
		
explist	: exp commaexps
		{
			$$ = $2;
			$$.push_back($1);
		}
		;
		
commaexps: TK_COMMA exp commaexps
		{
			$$ = $3;
			$$.push_back($2);
		}
		| {$$ = vector<Document *>();}
		;
		
exp		: TK_NIL
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetString("nil", allocator); 
			$$->AddMember("type", json_val, allocator);
			json_val.SetString("nil", allocator); 
			$$->AddMember("value", json_val, allocator);
		}
		|
		TK_FALSE
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetString("boolean", allocator); 
			$$->AddMember("type", json_val, allocator);
			json_val.SetBool(false); 
			$$->AddMember("value", json_val, allocator);
		}
		|
		TK_TRUE
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetString("boolean", allocator); 
			$$->AddMember("type", json_val, allocator);
			json_val.SetBool(true); 
			$$->AddMember("value", json_val, allocator);
		}
		|
		TK_NUMBER
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetString("double", allocator); 
			$$->AddMember("type", json_val, allocator);
			json_val.SetDouble($1); 
			$$->AddMember("value", json_val, allocator);
		}
		|
		TK_STRING
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetString("string", allocator); 
			$$->AddMember("type", json_val, allocator);
			json_val.SetString($1.c_str(), allocator); 
			$$->AddMember("value", json_val, allocator);
		}
		|
		TK_DOTS
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetString("dots", allocator); 
			$$->AddMember("type", json_val, allocator);
		}
		|
		functiondef
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetString("functiondef", allocator); 
			$$->AddMember("type", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("value", json_val, allocator);
		}
		|
		prefixexp
		{
			$$ = $1;
		}
		|
		tableconstructor
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetString("table", allocator);
			$$->AddMember("type", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("value", json_val, allocator);
		}
		|
		exp TK_PLUS exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();
			if (t1 == "double" && t2 == "double")
				json_val.SetString("double", allocator);
			else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
				json_val.SetString("unknown", allocator);
			else
				json_val.SetString("error", allocator);
			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_MINUS exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();
			if (t1 == "double" && t2 == "double")
				json_val.SetString("double", allocator);
			else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
				json_val.SetString("unknown", allocator);
			else
				json_val.SetString("error", allocator);
			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_MUL exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();
			if (t1 == "double" && t2 == "double")
				json_val.SetString("double", allocator);
			else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
				json_val.SetString("unknown", allocator);
			else
				json_val.SetString("error", allocator);
			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_DIV exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();
			if (t1 == "double" && t2 == "double")
				json_val.SetString("double", allocator);
			else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
				json_val.SetString("unknown", allocator);
			else
				json_val.SetString("error", allocator);
			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_CARET exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();
			if (t1 == "double" && t2 == "double")
				json_val.SetString("double", allocator);
			else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
				json_val.SetString("unknown", allocator);
			else
				json_val.SetString("error", allocator);
			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_PREC exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();

			if (t1 == "double" && t2 == "double")
				json_val.SetString("double", allocator);
			else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
				json_val.SetString("unknown", allocator);
			else
				json_val.SetString("error", allocator);

			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_CONCAT exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();

			if ((t1 == "string" || t1 == "double") && (t2 == "string" || t2 == "double"))
				json_val.SetString("string", allocator);
			else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
				json_val.SetString("unknown", allocator);
			else
				json_val.SetString("error", allocator);
			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_LT exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();

			if ((t1 == "double" && t2 == "double") || (t1 == "string" && t2 == "string"))
				json_val.SetString("boolean", allocator);
			else if (t1 == "table" && t2 == "table")
				json_val.SetString("unknown", allocator);
			else
				json_val.SetString("error", allocator);

			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_LE exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();

			if ((t1 == "double" && t2 == "double") || (t1 == "string" && t2 == "string"))
				json_val.SetString("boolean", allocator);
			else if (t1 == "table" && t2 == "table")
				json_val.SetString("unknown", allocator);
			else
				json_val.SetString("error", allocator);

			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_GR exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();

			if ((t1 == "double" && t2 == "double") || (t1 == "string" && t2 == "string"))
				json_val.SetString("boolean", allocator);
			else if (t1 == "table" && t2 == "table")
				json_val.SetString("unknown", allocator);
			else
				json_val.SetString("error", allocator);

			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_GE exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();

			if ((t1 == "double" && t2 == "double") || (t1 == "string" && t2 == "string"))
				json_val.SetString("boolean", allocator);
			else if (t1 == "table" && t2 == "table")
				json_val.SetString("unknown", allocator);
			else
				json_val.SetString("error", allocator);

			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_EQ exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();

			if (t1 == "error" || t2 == "error")
				json_val.SetString("error", allocator);
			else if (t1 == "table" && t2 == "table")
				json_val.SetString("boolean", allocator);

			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_NE exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();

			if (t1 == "error" || t2 == "error")
				json_val.SetString("error", allocator);
			else if (t1 == "table" && t2 == "table")
				json_val.SetString("boolean", allocator);

			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_AND exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();

			if (t1 == "error" || t2 == "error")
				json_val.SetString("error", allocator);
			else if (t1 == t2)
				json_val.SetString(t2.c_str(), allocator);
			else if (t1 == "nil" || t1 == "dots")
				json_val.SetString("nil", allocator);
			else if (t1 == "boolean")
				json_val.SetString("unknown", allocator);
			else if (t2 == "dots")
				json_val.SetString("nil", allocator);
			else
				json_val.SetString(t2.c_str(), allocator);

			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		exp TK_OR exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string t1 = (*$1)["type"].GetString();
			string t2 = (*$3)["type"].GetString();

			if (t1 == "error" || t2 == "error")
				json_val.SetString("error", allocator);
			else if (t1 == t2)
				json_val.SetString(t2.c_str(), allocator);
			else if (t1 == "nil" || t1 == "dots")
				json_val.SetString(t2.c_str(), allocator);
			else if (t1 == "boolean")
				json_val.SetString("unknown", allocator);
			else
				json_val.SetString(t1.c_str(), allocator);

			$$->AddMember("type", json_val, allocator);
			json_val.SetString($2.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$1, allocator); 
			$$->AddMember("first_argument", json_val, allocator);
			json_val.CopyFrom(*$3, allocator); 
			$$->AddMember("second_argument", json_val, allocator);
		}
		|
		TK_MINUS exp %prec UMINUS
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string tp = (*$2)["type"].GetString();

			if (tp == "double")
				json_val.SetString("double", allocator);
			else if (tp == "string")
				json_val.SetString("unknown", allocator);
			else
				json_val.SetString("error", allocator);

			$$->AddMember("type", json_val, allocator);
			json_val.SetString($1.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$2, allocator); 
			$$->AddMember("argument", json_val, allocator);
		}
		|
		TK_NOT exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string tp = (*$2)["type"].GetString();

			if (tp == "error")
				json_val.SetString("error", allocator);
			else
				json_val.SetString("boolean", allocator);

			$$->AddMember("type", json_val, allocator);
			json_val.SetString($1.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$2, allocator); 
			$$->AddMember("argument", json_val, allocator);
		}
		|
		TK_HASH exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			string tp = (*$2)["type"].GetString();

			if (tp == "string" || tp == "table")
				json_val.SetString("double", allocator);
			else
				json_val.SetString("error", allocator);

			$$->AddMember("type", json_val, allocator);
			json_val.SetString($1.c_str(), allocator); 
			$$->AddMember("operator", json_val, allocator);
			json_val.CopyFrom(*$2, allocator); 
			$$->AddMember("argument", json_val, allocator);
		}
		;

prefixexp: var
		{
			bool var = $1->FindMember("var_name") == $1->MemberEnd() ? false : true;
			if (var)
			{
				$$ = new Document();
				$$->SetObject();
				Value json_val;
				auto& allocator = $$->GetAllocator();
				json_val.SetString((*$1)["var_name"].GetString(), allocator);
				$$->AddMember("variable_name", json_val, allocator);
				pair<unsigned long long, string> p = t.get((*$1)["var_name"].GetString());
				json_val.SetString(p.second.c_str(), allocator);
				$$->AddMember("type", json_val, allocator);
				json_val.SetUint64(p.first);
				$$->AddMember("id", json_val, allocator);
			} else 
			{
				$$ = $1; 
				Value json_val;
				auto& allocator = $$->GetAllocator();
				json_val.SetString("unknown", allocator);
				$$->AddMember("type", json_val, allocator);
			}
		}
		|
		functioncall
		{
			$$ = $1; 
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetString("unknown", allocator); 
			$$->AddMember("type", json_val, allocator);
		}
		|
		TK_LB exp TK_RB { $$ = $2; }
		;

functioncall: var args
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$1, allocator);
			$$->AddMember("prefixexp", json_val, allocator);
			json_val.CopyFrom(*$2, allocator); 
			$$->AddMember("arguments", json_val, allocator);
		}
		|
		functioncall args
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$1, allocator);
			$$->AddMember("prefixexp", json_val, allocator);
			json_val.CopyFrom(*$2, allocator); 
			$$->AddMember("arguments", json_val, allocator);
		}
		|
		TK_LB exp TK_RB args
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$2, allocator);
			$$->AddMember("prefixexp", json_val, allocator);
			json_val.CopyFrom(*$4, allocator); 
			$$->AddMember("arguments", json_val, allocator);
		}
		|
		var TK_COLON TK_NAME args
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$1, allocator);
			$$->AddMember("prefixexp", json_val, allocator);
			json_val.SetString($3.c_str(), allocator);
			$$->AddMember("name", json_val, allocator);
			json_val.CopyFrom(*$4, allocator); 
			$$->AddMember("arguments", json_val, allocator);
		}
		|
		functioncall TK_COLON TK_NAME args
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$1, allocator);
			$$->AddMember("prefixexp", json_val, allocator);
			json_val.SetString($3.c_str(), allocator);
			$$->AddMember("name", json_val, allocator);
			json_val.CopyFrom(*$4, allocator); 
			$$->AddMember("arguments", json_val, allocator);
		}
		|
		TK_LB exp TK_RB TK_COLON TK_NAME args
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$2, allocator);
			$$->AddMember("prefixexp", json_val, allocator);
			json_val.SetString($5.c_str(), allocator);
			$$->AddMember("name", json_val, allocator);
			json_val.CopyFrom(*$6, allocator); 
			$$->AddMember("arguments", json_val, allocator);
		}
		;
		
args	: TK_LB opexplist TK_RB
		{
			$$ = new Document();
			$$->SetArray();
			auto& alloc = $$->GetAllocator();
			for (Document *d : $2)
				$$->PushBack(*d, alloc);
		}
		|
		tableconstructor
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$1, allocator);
			$$->AddMember("table", json_val, allocator);
		}
		|
		TK_STRING
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetString($1.c_str(), allocator);
			$$->AddMember("string", json_val, allocator);
		}
		;

functiondef: TK_FUNCTION funcbody
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$2, allocator);
			$$->AddMember("funcbody", json_val, allocator);
		}
		;

funcbody: {t.add_level();} TK_LB parlist TK_RB block TK_END
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$3, allocator);
			$$->AddMember("parlist", json_val, allocator);
			json_val.CopyFrom(*$5, allocator);
			$$->AddMember("block", json_val, allocator);
			t.delete_level();
		}
		;

parlist	: namelist opcommadots
		{
			Document d;
			auto& alloc = d.GetAllocator();
			d.SetArray();
			for (string s : $1)
			{
				Document *v = new Document();
				v->SetObject();
				auto& alc = v->GetAllocator();
				Value jv;
				jv.SetString(s.c_str(), alc);
				v->AddMember("variable_name", jv, alc);
				jv.SetString("unknown", alc);
				v->AddMember("type", jv, alc);
				jv.SetUint64(t.add_local(s, "unknown"));
				v->AddMember("id", jv, alc);
				d.PushBack(*v, alloc);
			}

			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(d, allocator);
			$$->AddMember("namelist", json_val, allocator);
			json_val.SetBool($2);
			$$->AddMember("dots", json_val, allocator);
		}
		|
		TK_DOTS
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetBool(true);
			$$->AddMember("dots", json_val, allocator);
		}
		|
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetBool(false);
			$$->AddMember("dots", json_val, allocator);
		}
		;
		
opcommadots: TK_COMMA TK_DOTS
		{
			$$ = true;
		}
		|
		{
			$$ = false;
		}
		;
		
tableconstructor: TK_LFB fieldlist TK_RFB
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$2, allocator);
			$$->AddMember("fieldlist", json_val, allocator);
		}
		;
		
fieldlist: field opsepfields opsep
		{
			$2.push_back($1);
			reverse($2.begin(), $2.end());
			$$ = new Document();
			$$->SetArray();
			auto& alloc = $$->GetAllocator();
			for (Document *d : $2)
			{
				$$->PushBack(*d, alloc);
			}
		}
		|
		{
			$$ = new Document();
			$$->SetObject();
		}
		;
		
opsepfields: fieldsep field opsepfields
		{
			$$ = $3;
			$$.push_back($2);
		}
		| {$$=vector<Document *>();}
		;

opsep	: fieldsep
		| {$$="";}
		;

field	: TK_LKB exp TK_RKB TK_UEQ exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$2, allocator);
			$$->AddMember("left_expression", json_val, allocator);
			json_val.CopyFrom(*$5, allocator);
			$$->AddMember("right_expression", json_val, allocator);
		}
		|
		TK_NAME TK_UEQ exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.SetString($1.c_str(), allocator);
			$$->AddMember("left_name", json_val, allocator);
			json_val.CopyFrom(*$3, allocator);
			$$->AddMember("right_expression", json_val, allocator);
		}
		|
		exp
		{
			$$ = new Document();
			$$->SetObject();
			Value json_val;
			auto& allocator = $$->GetAllocator();
			json_val.CopyFrom(*$1, allocator);
			$$->AddMember("expression", json_val, allocator);
		}
		;
		
fieldsep: TK_COMMA
		|
		TK_SEMICOLON
		;

%%

void yy::parser::error(const std::string& err){
    std::cout << "Error: " << err << std::endl;
    exit(-1);
}

string parse(char* file)
{
	try {
		set_input_file(file);
	}
	catch (int e)
	{
		cout << "Failed to open program code file\n";
		return "";
	}
	yy::parser parser;
	parser.parse();
	t.clear();
	close_input_file();
	StringBuffer buffer;
	PrettyWriter<StringBuffer> writer(buffer);
	root->Accept(writer);
	return buffer.GetString();
}
