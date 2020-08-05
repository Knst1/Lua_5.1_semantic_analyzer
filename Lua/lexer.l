%top{
    #include "y.tab.hpp"
	#include "globals.h"
    #define YY_DECL yy::parser::symbol_type yylex()

	bool debug = false;
	void log(std::string text)
	{
		if (debug)
			std::cout << "-> : " << text << std::endl;
	}
}

%option noyywrap nounput batch noinput

o              [ \t\v\a]*
sp             [ \t\r]+
name           [_a-zA-Z][_a-zA-Z0-9]*
n              [0-9]+
exp            [Ee][+-]?{n}
xn			   [0-9a-fA-F]+
xexp           [Pp][+-]?{xn}
number         ({n}|[.]{n}|{n}[.]|{n}[.]{n}){exp}?|[0][xX]({xn}|[.]{xn}|{xn}[.]|{xn}[.]{xn}){xexp}?

%x COMMENT
%x LONGCOMMENT
%x XLONGSTRING
%x XSTRINGQ
%x XSTRINGA

%%
^#!.*          { log(yytext); fprintf(yyout,"Пропущено: %s\n", yytext);   }
and            { log(yytext); return yy::parser::make_TK_AND(yytext);     }
break          { log(yytext); return yy::parser::make_TK_BREAK(yytext);   }
do             { log(yytext); return yy::parser::make_TK_DO(yytext);      }
else           { log(yytext); return yy::parser::make_TK_ELSE(yytext);    }
elseif         { log(yytext); return yy::parser::make_TK_ELSEIF(yytext);  }
end            { log(yytext); return yy::parser::make_TK_END(yytext);     }
false          { log(yytext); return yy::parser::make_TK_FALSE(yytext);   }
for            { log(yytext); return yy::parser::make_TK_FOR(yytext);     }
function       { log(yytext); return yy::parser::make_TK_FUNCTION(yytext);}
if             { log(yytext); return yy::parser::make_TK_IF(yytext);      }
in             { log(yytext); return yy::parser::make_TK_IN(yytext);      }
local          { log(yytext); return yy::parser::make_TK_LOCAL(yytext);   }
nil            { log(yytext); return yy::parser::make_TK_NIL(yytext);     }
not            { log(yytext); return yy::parser::make_TK_NOT(yytext);     }
or             { log(yytext); return yy::parser::make_TK_OR(yytext);      }
repeat         { log(yytext); return yy::parser::make_TK_REPEAT(yytext);  }
return         { log(yytext); return yy::parser::make_TK_RETURN(yytext);  }
then           { log(yytext); return yy::parser::make_TK_THEN(yytext);    }
true           { log(yytext); return yy::parser::make_TK_TRUE(yytext);    }
until          { log(yytext); return yy::parser::make_TK_UNTIL(yytext);   }
while          { log(yytext); return yy::parser::make_TK_WHILE(yytext);   }

{number}       { log(yytext);
				double d;
				sscanf_s(yytext, "%lf", &d);
				return yy::parser::make_TK_NUMBER(d);
			   }

{name}         {log(yytext); return yy::parser::make_TK_NAME(yytext);}

"[["({o}\n)?   yymore();BEGIN( XLONGSTRING );
"--[["         yymore(); BEGIN( LONGCOMMENT );
"--"           yymore(); BEGIN( COMMENT );

[\n]		   
{sp}           
"..."          { log(yytext); return yy::parser::make_TK_DOTS(yytext);     }
".."           { log(yytext); return yy::parser::make_TK_CONCAT(yytext);   }
"=="           { log(yytext); return yy::parser::make_TK_EQ(yytext);       }
">="           { log(yytext); return yy::parser::make_TK_GE(yytext);       }
"<="           { log(yytext); return yy::parser::make_TK_LE(yytext);       }
"~="           { log(yytext); return yy::parser::make_TK_NE(yytext);       }
";"            { log(yytext); return yy::parser::make_TK_SEMICOLON(yytext);}
":"            { log(yytext); return yy::parser::make_TK_COLON(yytext);    }
"-"            { log(yytext); return yy::parser::make_TK_MINUS(yytext);    }
"+"            { log(yytext); return yy::parser::make_TK_PLUS(yytext);     }
"*"            { log(yytext); return yy::parser::make_TK_MUL(yytext);      }
"/"            { log(yytext); return yy::parser::make_TK_DIV(yytext);      }
"="            { log(yytext); return yy::parser::make_TK_UEQ(yytext);      }
">"            { log(yytext); return yy::parser::make_TK_GR(yytext);       }
"<"            { log(yytext); return yy::parser::make_TK_LT(yytext);       }
"("            { log(yytext); return yy::parser::make_TK_LB(yytext);       }
")"            { log(yytext); return yy::parser::make_TK_RB(yytext);       }
"["            { log(yytext); return yy::parser::make_TK_LKB(yytext);      }
"]"            { log(yytext); return yy::parser::make_TK_RKB(yytext);      }
"{"            { log(yytext); return yy::parser::make_TK_LFB(yytext);      }
"}"            { log(yytext); return yy::parser::make_TK_RFB(yytext);      }
"^"            { log(yytext); return yy::parser::make_TK_CARET(yytext);    }
"%"            { log(yytext); return yy::parser::make_TK_PREC(yytext);     }
","            { log(yytext); return yy::parser::make_TK_COMMA(yytext);    }
"."            { log(yytext); return yy::parser::make_TK_DOT(yytext);      }
"#"            { log(yytext); return yy::parser::make_TK_HASH(yytext);     }
\"             yymore(); BEGIN(XSTRINGQ);
'              yymore(); BEGIN(XSTRINGA);

<XSTRINGQ>
{
  \"\"        yymore();
  \"           {BEGIN(0);
				std::string s(yytext);
				s.erase(0, 1);
				s.pop_back();
				log(s);
				return yy::parser::make_TK_STRING(s);
			}
  \\[abfnrtv] yymore();
  \\\n        yymore();
  \\\"        yymore();
  \\'         yymore();
  \\"["       yymore();
  \\"]"       yymore();
  [\n|\r]     {    fprintf(yyout, "Missing end of line.\n");
                      BEGIN(0);
                      return yy::parser::make_TK_STRING(std::string(yytext).erase(0, 1));
                  }
  .           yymore();
}

<XSTRINGA>
{
  ''          yymore();
  '          {BEGIN(0);
				std::string s(yytext);
				s.erase(0, 1);
				s.pop_back();
				log(s);
				return yy::parser::make_TK_STRING(s);
			}
  \\[abfnrtv] yymore();
  \\\n        yymore();
  \\\"        yymore();
  \\'         yymore();
  \\"["       yymore();
  \\"]"       yymore();
  [\n|\r]     {    fprintf(yyout, "Missing end of line.\n");
                      BEGIN(0);
					  return yy::parser::make_TK_STRING(std::string(yytext).erase(0, 1));
                  }
  .           yymore();
}

<XLONGSTRING>
{
  "]]"        {BEGIN(0);
				std::string s(yytext);
				s.erase(0, 2);
				s.pop_back();
				s.pop_back();
				log(s);
				return yy::parser::make_TK_STRING(s);
			}
  \n          yymore();
  \r          yymore();
  .           yymore();
}

<LONGCOMMENT>
{
  "]]"        {BEGIN(0);
				std::string s(yytext);
				log(s);
			}
  \n          yymore();
  \r          yymore();
  .           yymore();
}

<COMMENT>
{
  \n          {BEGIN(0);
				std::string s(yytext);
				log(s);
			}
  .           yymore();
}

<<EOF>>                 				{ log("EOF"); return yy::parser::make_QUIT(); }

%%
void set_input_file(char* filename)
{
	if (fopen_s(&yyin, filename, "r") != 0) 
		throw -1;
}

void close_input_file()
{
	fclose(yyin);
}