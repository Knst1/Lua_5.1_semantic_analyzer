// A Bison parser, made by GNU Bison 3.5.0.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.


#include "pch.h"

#include "../Lua/y.tab.hpp"


// Unqualified %code blocks.
#line 19 "parser.y"

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

#line 61 "y.tab.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 133 "y.tab.cpp"


	/* Return YYSTR after stripping away unnecessary quotes and
	   backslashes, so that it's suitable for yyerror.  The heuristic is
	   that double-quoting is unnecessary unless the string contains an
	   apostrophe, a comma, or backslash (other than backslash-backslash).
	   YYSTR is taken from yytname.  */
	std::string
		parser::yytnamerr_(const char *yystr)
	{
		if (*yystr == '"')
		{
			std::string yyr;
			char const *yyp = yystr;

			for (;;)
				switch (*++yyp)
				{
				case '\'':
				case ',':
					goto do_not_strip_quotes;

				case '\\':
					if (*++yyp != '\\')
						goto do_not_strip_quotes;
					else
						goto append;

				append:
				default:
					yyr += *yyp;
					break;

				case '"':
					return yyr;
				}
		do_not_strip_quotes:;
		}

		return yystr;
	}


	/// Build a parser object.
	parser::parser()
#if YYDEBUG
		: yydebug_(false),
		yycdebug_(&std::cerr)
#else

#endif
	{}

	parser::~parser()
	{}

	parser::syntax_error::~syntax_error() YY_NOEXCEPT YY_NOTHROW
	{}

	/*---------------.
	| Symbol types.  |
	`---------------*/



	// by_state.
	parser::by_state::by_state() YY_NOEXCEPT
		: state(empty_state)
	{}

	parser::by_state::by_state(const by_state& that) YY_NOEXCEPT
		: state(that.state)
	{}

	void
		parser::by_state::clear() YY_NOEXCEPT
	{
		state = empty_state;
	}

	void
		parser::by_state::move(by_state& that)
	{
		state = that.state;
		that.clear();
	}

	parser::by_state::by_state(state_type s) YY_NOEXCEPT
		: state(s)
	{}

	parser::symbol_number_type
		parser::by_state::type_get() const YY_NOEXCEPT
	{
		if (state == empty_state)
			return empty_symbol;
		else
			return yystos_[state];
	}

	parser::stack_symbol_type::stack_symbol_type()
	{}

	parser::stack_symbol_type::stack_symbol_type(YY_RVREF(stack_symbol_type) that)
		: super_type(YY_MOVE(that.state))
	{
		switch (that.type_get())
		{
		case 90: // opcommadots
			value.YY_MOVE_OR_COPY< bool >(YY_MOVE(that.value));
			break;

		case 23: // TK_NUMBER
			value.YY_MOVE_OR_COPY< double >(YY_MOVE(that.value));
			break;

		case 57: // program
		case 58: // block
		case 61: // stat
		case 64: // forstep
		case 66: // elseif
		case 68: // else
		case 69: // retstat
		case 72: // funcname
		case 77: // var
		case 82: // exp
		case 83: // prefixexp
		case 84: // functioncall
		case 85: // args
		case 86: // functiondef
		case 87: // funcbody
		case 89: // parlist
		case 91: // tableconstructor
		case 92: // fieldlist
		case 95: // field
			value.YY_MOVE_OR_COPY< rapidjson::Document * >(YY_MOVE(that.value));
			break;

		case 3: // TK_NAME
		case 4: // TK_BREAK
		case 5: // TK_DO
		case 6: // TK_ELSE
		case 7: // TK_ELSEIF
		case 8: // TK_END
		case 9: // TK_FALSE
		case 10: // TK_FOR
		case 11: // TK_FUNCTION
		case 12: // TK_IF
		case 13: // TK_IN
		case 14: // TK_LOCAL
		case 15: // TK_NIL
		case 16: // TK_REPEAT
		case 17: // TK_RETURN
		case 18: // TK_THEN
		case 19: // TK_TRUE
		case 20: // TK_UNTIL
		case 21: // TK_WHILE
		case 22: // TK_DOTS
		case 24: // TK_STRING
		case 25: // TK_WHITESPACE
		case 26: // TK_BADCHAR
		case 27: // TK_SEMICOLON
		case 28: // TK_COLON
		case 29: // TK_UEQ
		case 30: // TK_LB
		case 31: // TK_RB
		case 32: // TK_LKB
		case 33: // TK_RKB
		case 34: // TK_LFB
		case 35: // TK_RFB
		case 36: // TK_COMMA
		case 37: // TK_DOT
		case 38: // TK_OR
		case 39: // TK_AND
		case 40: // TK_LT
		case 41: // TK_GR
		case 42: // TK_GE
		case 43: // TK_LE
		case 44: // TK_EQ
		case 45: // TK_NE
		case 46: // TK_CONCAT
		case 47: // TK_PLUS
		case 48: // TK_MINUS
		case 49: // TK_MUL
		case 50: // TK_DIV
		case 51: // TK_PREC
		case 52: // TK_CARET
		case 53: // TK_NOT
		case 54: // TK_HASH
		case 71: // opsemicolon
		case 74: // colonname
		case 94: // opsep
		case 96: // fieldsep
			value.YY_MOVE_OR_COPY< std::string >(YY_MOVE(that.value));
			break;

		case 60: // opstat
		case 65: // eqexplist
		case 67: // elseifs
		case 70: // opexplist
		case 75: // varlist
		case 76: // commavar
		case 80: // explist
		case 81: // commaexps
		case 93: // opsepfields
			value.YY_MOVE_OR_COPY< std::vector<rapidjson::Document *> >(YY_MOVE(that.value));
			break;

		case 73: // dotnames
		case 78: // namelist
		case 79: // commanames
			value.YY_MOVE_OR_COPY< std::vector<std::string> >(YY_MOVE(that.value));
			break;

		default:
			break;
		}

#if 201103L <= YY_CPLUSPLUS
		// that is emptied.
		that.state = empty_state;
#endif
	}

	parser::stack_symbol_type::stack_symbol_type(state_type s, YY_MOVE_REF(symbol_type) that)
		: super_type(s)
	{
		switch (that.type_get())
		{
		case 90: // opcommadots
			value.move< bool >(YY_MOVE(that.value));
			break;

		case 23: // TK_NUMBER
			value.move< double >(YY_MOVE(that.value));
			break;

		case 57: // program
		case 58: // block
		case 61: // stat
		case 64: // forstep
		case 66: // elseif
		case 68: // else
		case 69: // retstat
		case 72: // funcname
		case 77: // var
		case 82: // exp
		case 83: // prefixexp
		case 84: // functioncall
		case 85: // args
		case 86: // functiondef
		case 87: // funcbody
		case 89: // parlist
		case 91: // tableconstructor
		case 92: // fieldlist
		case 95: // field
			value.move< rapidjson::Document * >(YY_MOVE(that.value));
			break;

		case 3: // TK_NAME
		case 4: // TK_BREAK
		case 5: // TK_DO
		case 6: // TK_ELSE
		case 7: // TK_ELSEIF
		case 8: // TK_END
		case 9: // TK_FALSE
		case 10: // TK_FOR
		case 11: // TK_FUNCTION
		case 12: // TK_IF
		case 13: // TK_IN
		case 14: // TK_LOCAL
		case 15: // TK_NIL
		case 16: // TK_REPEAT
		case 17: // TK_RETURN
		case 18: // TK_THEN
		case 19: // TK_TRUE
		case 20: // TK_UNTIL
		case 21: // TK_WHILE
		case 22: // TK_DOTS
		case 24: // TK_STRING
		case 25: // TK_WHITESPACE
		case 26: // TK_BADCHAR
		case 27: // TK_SEMICOLON
		case 28: // TK_COLON
		case 29: // TK_UEQ
		case 30: // TK_LB
		case 31: // TK_RB
		case 32: // TK_LKB
		case 33: // TK_RKB
		case 34: // TK_LFB
		case 35: // TK_RFB
		case 36: // TK_COMMA
		case 37: // TK_DOT
		case 38: // TK_OR
		case 39: // TK_AND
		case 40: // TK_LT
		case 41: // TK_GR
		case 42: // TK_GE
		case 43: // TK_LE
		case 44: // TK_EQ
		case 45: // TK_NE
		case 46: // TK_CONCAT
		case 47: // TK_PLUS
		case 48: // TK_MINUS
		case 49: // TK_MUL
		case 50: // TK_DIV
		case 51: // TK_PREC
		case 52: // TK_CARET
		case 53: // TK_NOT
		case 54: // TK_HASH
		case 71: // opsemicolon
		case 74: // colonname
		case 94: // opsep
		case 96: // fieldsep
			value.move< std::string >(YY_MOVE(that.value));
			break;

		case 60: // opstat
		case 65: // eqexplist
		case 67: // elseifs
		case 70: // opexplist
		case 75: // varlist
		case 76: // commavar
		case 80: // explist
		case 81: // commaexps
		case 93: // opsepfields
			value.move< std::vector<rapidjson::Document *> >(YY_MOVE(that.value));
			break;

		case 73: // dotnames
		case 78: // namelist
		case 79: // commanames
			value.move< std::vector<std::string> >(YY_MOVE(that.value));
			break;

		default:
			break;
		}

		// that is emptied.
		that.type = empty_symbol;
	}

#if YY_CPLUSPLUS < 201103L
	parser::stack_symbol_type&
		parser::stack_symbol_type::operator= (const stack_symbol_type& that)
	{
		state = that.state;
		switch (that.type_get())
		{
		case 90: // opcommadots
			value.copy< bool >(that.value);
			break;

		case 23: // TK_NUMBER
			value.copy< double >(that.value);
			break;

		case 57: // program
		case 58: // block
		case 61: // stat
		case 64: // forstep
		case 66: // elseif
		case 68: // else
		case 69: // retstat
		case 72: // funcname
		case 77: // var
		case 82: // exp
		case 83: // prefixexp
		case 84: // functioncall
		case 85: // args
		case 86: // functiondef
		case 87: // funcbody
		case 89: // parlist
		case 91: // tableconstructor
		case 92: // fieldlist
		case 95: // field
			value.copy< rapidjson::Document * >(that.value);
			break;

		case 3: // TK_NAME
		case 4: // TK_BREAK
		case 5: // TK_DO
		case 6: // TK_ELSE
		case 7: // TK_ELSEIF
		case 8: // TK_END
		case 9: // TK_FALSE
		case 10: // TK_FOR
		case 11: // TK_FUNCTION
		case 12: // TK_IF
		case 13: // TK_IN
		case 14: // TK_LOCAL
		case 15: // TK_NIL
		case 16: // TK_REPEAT
		case 17: // TK_RETURN
		case 18: // TK_THEN
		case 19: // TK_TRUE
		case 20: // TK_UNTIL
		case 21: // TK_WHILE
		case 22: // TK_DOTS
		case 24: // TK_STRING
		case 25: // TK_WHITESPACE
		case 26: // TK_BADCHAR
		case 27: // TK_SEMICOLON
		case 28: // TK_COLON
		case 29: // TK_UEQ
		case 30: // TK_LB
		case 31: // TK_RB
		case 32: // TK_LKB
		case 33: // TK_RKB
		case 34: // TK_LFB
		case 35: // TK_RFB
		case 36: // TK_COMMA
		case 37: // TK_DOT
		case 38: // TK_OR
		case 39: // TK_AND
		case 40: // TK_LT
		case 41: // TK_GR
		case 42: // TK_GE
		case 43: // TK_LE
		case 44: // TK_EQ
		case 45: // TK_NE
		case 46: // TK_CONCAT
		case 47: // TK_PLUS
		case 48: // TK_MINUS
		case 49: // TK_MUL
		case 50: // TK_DIV
		case 51: // TK_PREC
		case 52: // TK_CARET
		case 53: // TK_NOT
		case 54: // TK_HASH
		case 71: // opsemicolon
		case 74: // colonname
		case 94: // opsep
		case 96: // fieldsep
			value.copy< std::string >(that.value);
			break;

		case 60: // opstat
		case 65: // eqexplist
		case 67: // elseifs
		case 70: // opexplist
		case 75: // varlist
		case 76: // commavar
		case 80: // explist
		case 81: // commaexps
		case 93: // opsepfields
			value.copy< std::vector<rapidjson::Document *> >(that.value);
			break;

		case 73: // dotnames
		case 78: // namelist
		case 79: // commanames
			value.copy< std::vector<std::string> >(that.value);
			break;

		default:
			break;
		}

		return *this;
	}

	parser::stack_symbol_type&
		parser::stack_symbol_type::operator= (stack_symbol_type& that)
	{
		state = that.state;
		switch (that.type_get())
		{
		case 90: // opcommadots
			value.move< bool >(that.value);
			break;

		case 23: // TK_NUMBER
			value.move< double >(that.value);
			break;

		case 57: // program
		case 58: // block
		case 61: // stat
		case 64: // forstep
		case 66: // elseif
		case 68: // else
		case 69: // retstat
		case 72: // funcname
		case 77: // var
		case 82: // exp
		case 83: // prefixexp
		case 84: // functioncall
		case 85: // args
		case 86: // functiondef
		case 87: // funcbody
		case 89: // parlist
		case 91: // tableconstructor
		case 92: // fieldlist
		case 95: // field
			value.move< rapidjson::Document * >(that.value);
			break;

		case 3: // TK_NAME
		case 4: // TK_BREAK
		case 5: // TK_DO
		case 6: // TK_ELSE
		case 7: // TK_ELSEIF
		case 8: // TK_END
		case 9: // TK_FALSE
		case 10: // TK_FOR
		case 11: // TK_FUNCTION
		case 12: // TK_IF
		case 13: // TK_IN
		case 14: // TK_LOCAL
		case 15: // TK_NIL
		case 16: // TK_REPEAT
		case 17: // TK_RETURN
		case 18: // TK_THEN
		case 19: // TK_TRUE
		case 20: // TK_UNTIL
		case 21: // TK_WHILE
		case 22: // TK_DOTS
		case 24: // TK_STRING
		case 25: // TK_WHITESPACE
		case 26: // TK_BADCHAR
		case 27: // TK_SEMICOLON
		case 28: // TK_COLON
		case 29: // TK_UEQ
		case 30: // TK_LB
		case 31: // TK_RB
		case 32: // TK_LKB
		case 33: // TK_RKB
		case 34: // TK_LFB
		case 35: // TK_RFB
		case 36: // TK_COMMA
		case 37: // TK_DOT
		case 38: // TK_OR
		case 39: // TK_AND
		case 40: // TK_LT
		case 41: // TK_GR
		case 42: // TK_GE
		case 43: // TK_LE
		case 44: // TK_EQ
		case 45: // TK_NE
		case 46: // TK_CONCAT
		case 47: // TK_PLUS
		case 48: // TK_MINUS
		case 49: // TK_MUL
		case 50: // TK_DIV
		case 51: // TK_PREC
		case 52: // TK_CARET
		case 53: // TK_NOT
		case 54: // TK_HASH
		case 71: // opsemicolon
		case 74: // colonname
		case 94: // opsep
		case 96: // fieldsep
			value.move< std::string >(that.value);
			break;

		case 60: // opstat
		case 65: // eqexplist
		case 67: // elseifs
		case 70: // opexplist
		case 75: // varlist
		case 76: // commavar
		case 80: // explist
		case 81: // commaexps
		case 93: // opsepfields
			value.move< std::vector<rapidjson::Document *> >(that.value);
			break;

		case 73: // dotnames
		case 78: // namelist
		case 79: // commanames
			value.move< std::vector<std::string> >(that.value);
			break;

		default:
			break;
		}

		// that is emptied.
		that.state = empty_state;
		return *this;
	}
#endif

	template <typename Base>
	void
		parser::yy_destroy_(const char* yymsg, basic_symbol<Base>& yysym) const
	{
		if (yymsg)
			YY_SYMBOL_PRINT(yymsg, yysym);
	}

#if YYDEBUG
	template <typename Base>
	void
		parser::yy_print_(std::ostream& yyo,
			const basic_symbol<Base>& yysym) const
	{
		std::ostream& yyoutput = yyo;
		YYUSE(yyoutput);
		symbol_number_type yytype = yysym.type_get();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
		// Avoid a (spurious) G++ 4.8 warning about "array subscript is
		// below array bounds".
		if (yysym.empty())
			std::abort();
#endif
		yyo << (yytype < yyntokens_ ? "token" : "nterm")
			<< ' ' << yytname_[yytype] << " (";
		YYUSE(yytype);
		yyo << ')';
	}
#endif

	void
		parser::yypush_(const char* m, YY_MOVE_REF(stack_symbol_type) sym)
	{
		if (m)
			YY_SYMBOL_PRINT(m, sym);
		yystack_.push(YY_MOVE(sym));
	}

	void
		parser::yypush_(const char* m, state_type s, YY_MOVE_REF(symbol_type) sym)
	{
#if 201103L <= YY_CPLUSPLUS
		yypush_(m, stack_symbol_type(s, std::move(sym)));
#else
		stack_symbol_type ss(s, sym);
		yypush_(m, ss);
#endif
	}

	void
		parser::yypop_(int n)
	{
		yystack_.pop(n);
	}

#if YYDEBUG
	std::ostream&
		parser::debug_stream() const
	{
		return *yycdebug_;
	}

	void
		parser::set_debug_stream(std::ostream& o)
	{
		yycdebug_ = &o;
	}


	parser::debug_level_type
		parser::debug_level() const
	{
		return yydebug_;
	}

	void
		parser::set_debug_level(debug_level_type l)
	{
		yydebug_ = l;
	}
#endif // YYDEBUG

	parser::state_type
		parser::yy_lr_goto_state_(state_type yystate, int yysym)
	{
		int yyr = yypgoto_[yysym - yyntokens_] + yystate;
		if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
			return yytable_[yyr];
		else
			return yydefgoto_[yysym - yyntokens_];
	}

	bool
		parser::yy_pact_value_is_default_(int yyvalue)
	{
		return yyvalue == yypact_ninf_;
	}

	bool
		parser::yy_table_value_is_error_(int yyvalue)
	{
		return yyvalue == yytable_ninf_;
	}

	int
		parser::operator() ()
	{
		return parse();
	}

	int
		parser::parse()
	{
		int yyn;
		/// Length of the RHS of the rule being reduced.
		int yylen = 0;

		// Error handling.
		int yynerrs_ = 0;
		int yyerrstatus_ = 0;

		/// The lookahead symbol.
		symbol_type yyla;

		/// The return value of parse ().
		int yyresult;

#if YY_EXCEPTIONS
		try
#endif // YY_EXCEPTIONS
		{
			YYCDEBUG << "Starting parse\n";


			/* Initialize the stack.  The initial state will be set in
			   yynewstate, since the latter expects the semantical and the
			   location values to have been already stored, initialize these
			   stacks with a primary value.  */
			yystack_.clear();
			yypush_(YY_NULLPTR, 0, YY_MOVE(yyla));

			/*-----------------------------------------------.
			| yynewstate -- push a new symbol on the stack.  |
			`-----------------------------------------------*/
		yynewstate:
			YYCDEBUG << "Entering state " << int(yystack_[0].state) << '\n';

			// Accept?
			if (yystack_[0].state == yyfinal_)
				YYACCEPT;

			goto yybackup;


			/*-----------.
			| yybackup.  |
			`-----------*/
		yybackup:
			// Try to take a decision without lookahead.
			yyn = yypact_[yystack_[0].state];
			if (yy_pact_value_is_default_(yyn))
				goto yydefault;

			// Read a lookahead token.
			if (yyla.empty())
			{
				YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
				try
#endif // YY_EXCEPTIONS
				{
					symbol_type yylookahead(yylex());
					yyla.move(yylookahead);
				}
#if YY_EXCEPTIONS
				catch (const syntax_error& yyexc)
				{
					YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
					error(yyexc);
					goto yyerrlab1;
				}
#endif // YY_EXCEPTIONS
			}
			YY_SYMBOL_PRINT("Next token is", yyla);

			/* If the proper action on seeing token YYLA.TYPE is to reduce or
			   to detect an error, take that action.  */
			yyn += yyla.type_get();
			if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get())
			{
				goto yydefault;
			}

			// Reduce or error.
			yyn = yytable_[yyn];
			if (yyn <= 0)
			{
				if (yy_table_value_is_error_(yyn))
					goto yyerrlab;
				yyn = -yyn;
				goto yyreduce;
			}

			// Count tokens shifted since error; after three, turn off error status.
			if (yyerrstatus_)
				--yyerrstatus_;

			// Shift the lookahead token.
			yypush_("Shifting", static_cast<state_type> (yyn), YY_MOVE(yyla));
			goto yynewstate;


			/*-----------------------------------------------------------.
			| yydefault -- do the default action for the current state.  |
			`-----------------------------------------------------------*/
		yydefault:
			yyn = yydefact_[yystack_[0].state];
			if (yyn == 0)
				goto yyerrlab;
			goto yyreduce;


			/*-----------------------------.
			| yyreduce -- do a reduction.  |
			`-----------------------------*/
		yyreduce:
			yylen = yyr2_[yyn];
			{
				stack_symbol_type yylhs;
				yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
				/* Variants are always initialized to an empty instance of the
				   correct type. The default '$$ = $1' action is NOT applied
				   when using variants.  */
				switch (yyr1_[yyn])
				{
				case 90: // opcommadots
					yylhs.value.emplace< bool >();
					break;

				case 23: // TK_NUMBER
					yylhs.value.emplace< double >();
					break;

				case 57: // program
				case 58: // block
				case 61: // stat
				case 64: // forstep
				case 66: // elseif
				case 68: // else
				case 69: // retstat
				case 72: // funcname
				case 77: // var
				case 82: // exp
				case 83: // prefixexp
				case 84: // functioncall
				case 85: // args
				case 86: // functiondef
				case 87: // funcbody
				case 89: // parlist
				case 91: // tableconstructor
				case 92: // fieldlist
				case 95: // field
					yylhs.value.emplace< rapidjson::Document * >();
					break;

				case 3: // TK_NAME
				case 4: // TK_BREAK
				case 5: // TK_DO
				case 6: // TK_ELSE
				case 7: // TK_ELSEIF
				case 8: // TK_END
				case 9: // TK_FALSE
				case 10: // TK_FOR
				case 11: // TK_FUNCTION
				case 12: // TK_IF
				case 13: // TK_IN
				case 14: // TK_LOCAL
				case 15: // TK_NIL
				case 16: // TK_REPEAT
				case 17: // TK_RETURN
				case 18: // TK_THEN
				case 19: // TK_TRUE
				case 20: // TK_UNTIL
				case 21: // TK_WHILE
				case 22: // TK_DOTS
				case 24: // TK_STRING
				case 25: // TK_WHITESPACE
				case 26: // TK_BADCHAR
				case 27: // TK_SEMICOLON
				case 28: // TK_COLON
				case 29: // TK_UEQ
				case 30: // TK_LB
				case 31: // TK_RB
				case 32: // TK_LKB
				case 33: // TK_RKB
				case 34: // TK_LFB
				case 35: // TK_RFB
				case 36: // TK_COMMA
				case 37: // TK_DOT
				case 38: // TK_OR
				case 39: // TK_AND
				case 40: // TK_LT
				case 41: // TK_GR
				case 42: // TK_GE
				case 43: // TK_LE
				case 44: // TK_EQ
				case 45: // TK_NE
				case 46: // TK_CONCAT
				case 47: // TK_PLUS
				case 48: // TK_MINUS
				case 49: // TK_MUL
				case 50: // TK_DIV
				case 51: // TK_PREC
				case 52: // TK_CARET
				case 53: // TK_NOT
				case 54: // TK_HASH
				case 71: // opsemicolon
				case 74: // colonname
				case 94: // opsep
				case 96: // fieldsep
					yylhs.value.emplace< std::string >();
					break;

				case 60: // opstat
				case 65: // eqexplist
				case 67: // elseifs
				case 70: // opexplist
				case 75: // varlist
				case 76: // commavar
				case 80: // explist
				case 81: // commaexps
				case 93: // opsepfields
					yylhs.value.emplace< std::vector<rapidjson::Document *> >();
					break;

				case 73: // dotnames
				case 78: // namelist
				case 79: // commanames
					yylhs.value.emplace< std::vector<std::string> >();
					break;

				default:
					break;
				}



				// Perform the reduction.
				YY_REDUCE_PRINT(yyn);
#if YY_EXCEPTIONS
				try
#endif // YY_EXCEPTIONS
				{
					switch (yyn)
					{
					case 2:
#line 127 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = yystack_[0].value.as < rapidjson::Document * >();
						root = yylhs.value.as < rapidjson::Document * >();
					}
#line 1080 "y.tab.cpp"
					break;

					case 3:
#line 132 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						root = yylhs.value.as < rapidjson::Document * >();
					}
#line 1090 "y.tab.cpp"
					break;

					case 4:
#line 139 "parser.y"
					{t.add_level(); }
#line 1096 "y.tab.cpp"
					break;

					case 5:
#line 141 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						reverse(yystack_[1].value.as < std::vector<rapidjson::Document *> >().begin(), yystack_[1].value.as < std::vector<rapidjson::Document *> >().end());

						Document doc;
						auto& alloc = doc.GetAllocator();
						doc.SetArray();
						for (Document *d : yystack_[1].value.as < std::vector<rapidjson::Document *> >())
							if (d->IsArray())
								for (SizeType i = 0; i < d->Size(); i++)
									doc.PushBack((*d)[i], alloc);
							else
								doc.PushBack(*d, alloc);

						json_val.CopyFrom(doc, allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("states", json_val, allocator);
						if (!yystack_[0].value.as < rapidjson::Document * >()->ObjectEmpty())
						{
							json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
							yylhs.value.as < rapidjson::Document * >()->AddMember("retstat", json_val, allocator);
						}
						t.delete_level();
					}
#line 1127 "y.tab.cpp"
					break;

					case 6:
#line 170 "parser.y"
					{
						yylhs.value.as < std::vector<rapidjson::Document *> >() = yystack_[0].value.as < std::vector<rapidjson::Document *> >();
						yylhs.value.as < std::vector<rapidjson::Document *> >().push_back(yystack_[1].value.as < rapidjson::Document * >());
					}
#line 1136 "y.tab.cpp"
					break;

					case 7:
#line 176 "parser.y"
					{
						yylhs.value.as < std::vector<rapidjson::Document *> >() = yystack_[0].value.as < std::vector<rapidjson::Document *> >();
					}
#line 1144 "y.tab.cpp"
					break;

					case 8:
#line 179 "parser.y"
					{yylhs.value.as < std::vector<rapidjson::Document *> >() = vector<Document *>(); }
#line 1150 "y.tab.cpp"
					break;

					case 9:
#line 183 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetArray();
						auto& alloc = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						reverse(yystack_[2].value.as < std::vector<rapidjson::Document *> >().begin(), yystack_[2].value.as < std::vector<rapidjson::Document *> >().end());
						reverse(yystack_[0].value.as < std::vector<rapidjson::Document *> >().begin(), yystack_[0].value.as < std::vector<rapidjson::Document *> >().end());
						for (int i = 0; i < min(yystack_[2].value.as < std::vector<rapidjson::Document *> >().size(), yystack_[0].value.as < std::vector<rapidjson::Document *> >().size()); i++)
						{
							Document *d = new Document();
							d->SetObject();
							auto& allocator = d->GetAllocator();
							Value json_val;

							bool var = (*yystack_[2].value.as < std::vector<rapidjson::Document *> >()[i]).FindMember("var_name") == (*yystack_[2].value.as < std::vector<rapidjson::Document *> >()[i]).MemberEnd() ? false : true;
							if (var)
							{
								json_val.SetString((*yystack_[2].value.as < std::vector<rapidjson::Document *> >()[i])["var_name"].GetString(), allocator);
								d->AddMember("variable_name", json_val, allocator);
								json_val.SetString((*yystack_[0].value.as < std::vector<rapidjson::Document *> >()[i])["type"].GetString(), allocator);
								d->AddMember("type", json_val, allocator);
								json_val.SetUint64(t.add((*yystack_[2].value.as < std::vector<rapidjson::Document *> >()[i])["var_name"].GetString(), (*yystack_[0].value.as < std::vector<rapidjson::Document *> >()[i])["type"].GetString()));
								d->AddMember("id", json_val, allocator);
							}
							else
							{
								json_val.CopyFrom(*yystack_[2].value.as < std::vector<rapidjson::Document *> >()[i], allocator);
								d->AddMember("variable", json_val, allocator);
							}

							json_val.CopyFrom(*yystack_[0].value.as < std::vector<rapidjson::Document *> >()[i], allocator);
							d->AddMember("expression", json_val, allocator);

							Document *assigment = new Document();
							assigment->SetObject();
							auto& asg_allocator = assigment->GetAllocator();
							Value asg_json_val;
							asg_json_val.CopyFrom(*d, asg_allocator);
							assigment->AddMember("assigment", asg_json_val, asg_allocator);

							yylhs.value.as < rapidjson::Document * >()->PushBack(*assigment, alloc);
						}
						for (int i = yystack_[0].value.as < std::vector<rapidjson::Document *> >().size(); i < yystack_[2].value.as < std::vector<rapidjson::Document *> >().size(); i++)
						{
							Document *d = new Document();
							d->SetObject();
							auto& allocator = d->GetAllocator();
							Value json_val;

							bool var = (*yystack_[2].value.as < std::vector<rapidjson::Document *> >()[i]).FindMember("var_name") == (*yystack_[2].value.as < std::vector<rapidjson::Document *> >()[i]).MemberEnd() ? false : true;
							if (var)
							{
								json_val.SetString((*yystack_[2].value.as < std::vector<rapidjson::Document *> >()[i])["var_name"].GetString(), allocator);
								d->AddMember("variable_name", json_val, allocator);
								json_val.SetString("nil", allocator);
								d->AddMember("type", json_val, allocator);
								json_val.SetUint64(t.add((*yystack_[2].value.as < std::vector<rapidjson::Document *> >()[i])["var_name"].GetString(), "nil"));
								d->AddMember("id", json_val, allocator);
							}
							else
							{
								json_val.CopyFrom(*yystack_[2].value.as < std::vector<rapidjson::Document *> >()[i], allocator);
								d->AddMember("variable", json_val, allocator);
							}

							Document *assigment = new Document();
							assigment->SetObject();
							auto& asg_allocator = assigment->GetAllocator();
							Value asg_json_val;
							asg_json_val.CopyFrom(*d, asg_allocator);
							assigment->AddMember("assigment", asg_json_val, asg_allocator);

							yylhs.value.as < rapidjson::Document * >()->PushBack(*assigment, alloc);
						}
					}
#line 1227 "y.tab.cpp"
					break;

					case 10:
#line 257 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("functioncall", json_val, allocator);
					}
#line 1240 "y.tab.cpp"
					break;

					case 11:
#line 267 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = yystack_[1].value.as < rapidjson::Document * >();
					}
#line 1248 "y.tab.cpp"
					break;

					case 12:
#line 272 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();

						Document *whl = new Document();
						whl->SetObject();
						auto& whl_allocator = whl->GetAllocator();
						Value json_val;
						json_val.CopyFrom(*yystack_[3].value.as < rapidjson::Document * >(), whl_allocator);
						whl->AddMember("condition", json_val, whl_allocator);
						json_val.CopyFrom(*yystack_[1].value.as < rapidjson::Document * >(), whl_allocator);
						whl->AddMember("block", json_val, whl_allocator);

						json_val.CopyFrom(*whl, allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("while", json_val, allocator);
					}
#line 1270 "y.tab.cpp"
					break;

					case 13:
#line 291 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();

						Document *rpt = new Document();
						rpt->SetObject();
						auto& rpt_allocator = rpt->GetAllocator();
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), rpt_allocator);
						rpt->AddMember("condition", json_val, rpt_allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), rpt_allocator);
						rpt->AddMember("block", json_val, rpt_allocator);

						json_val.CopyFrom(*rpt, allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("repeat", json_val, allocator);
					}
#line 1292 "y.tab.cpp"
					break;

					case 14:
#line 310 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();

						Document *ifd = new Document();
						ifd->SetObject();
						auto& if_allocator = ifd->GetAllocator();
						json_val.CopyFrom(*yystack_[5].value.as < rapidjson::Document * >(), if_allocator);
						ifd->AddMember("condition", json_val, if_allocator);
						json_val.CopyFrom(*yystack_[3].value.as < rapidjson::Document * >(), if_allocator);
						ifd->AddMember("then", json_val, if_allocator);
						reverse(yystack_[2].value.as < std::vector<rapidjson::Document *> >().begin(), yystack_[2].value.as < std::vector<rapidjson::Document *> >().end());
						if (yystack_[2].value.as < std::vector<rapidjson::Document *> >().size() > 0)
						{
							Document *elseifs = new Document();
							elseifs->SetArray();
							auto& elseifs_allocator = elseifs->GetAllocator();
							for (Document *d : yystack_[2].value.as < std::vector<rapidjson::Document *> >())
								elseifs->PushBack(*d, elseifs_allocator);
							json_val.CopyFrom(*elseifs, if_allocator);
							ifd->AddMember("elseifs", json_val, if_allocator);
						}

						if (!yystack_[1].value.as < rapidjson::Document * >()->ObjectEmpty())
						{
							json_val.CopyFrom(*yystack_[1].value.as < rapidjson::Document * >(), if_allocator);
							ifd->AddMember("else", json_val, if_allocator);
						}
						json_val.CopyFrom(*ifd, allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("if", json_val, allocator);
					}
#line 1330 "y.tab.cpp"
					break;

					case 15:
#line 345 "parser.y"
					{
						t.add_level();

						string t1 = (*yystack_[3].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[1].value.as < rapidjson::Document * >())["type"].GetString();
						string t3 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();
						string tp;
						if (t1 == "double" && t2 == "double" && t3 == "double")
							tp = "double";
						else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown") && (t3 == "string" || t3 == "double" || t3 == "unknown"))
							tp = "unknown";
						else
							tp = "error";
						t.add_local(yystack_[5].value.as < std::string >(), tp);
					}
#line 1350 "y.tab.cpp"
					break;

					case 16:
#line 361 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();

						Document *ford = new Document();
						ford->SetObject();
						auto& for_allocator = ford->GetAllocator();

						json_val.SetString(yystack_[9].value.as < std::string >().c_str(), for_allocator);
						ford->AddMember("control_variable_name", json_val, for_allocator);

						pair<unsigned long long, string> p = t.get(yystack_[9].value.as < std::string >());

						json_val.SetString(p.second.c_str(), for_allocator);
						ford->AddMember("type", json_val, for_allocator);
						json_val.SetUint64(p.first);
						ford->AddMember("control_variable_id", json_val, for_allocator);
						json_val.CopyFrom(*yystack_[7].value.as < rapidjson::Document * >(), for_allocator);
						ford->AddMember("begin", json_val, for_allocator);
						json_val.CopyFrom(*yystack_[5].value.as < rapidjson::Document * >(), for_allocator);
						ford->AddMember("end", json_val, for_allocator);
						json_val.CopyFrom(*yystack_[4].value.as < rapidjson::Document * >(), for_allocator);
						ford->AddMember("step", json_val, for_allocator);
						json_val.CopyFrom(*yystack_[1].value.as < rapidjson::Document * >(), for_allocator);
						ford->AddMember("block", json_val, for_allocator);

						json_val.CopyFrom(*ford, allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("for", json_val, allocator);

						t.delete_level();
					}
#line 1388 "y.tab.cpp"
					break;

					case 17:
#line 396 "parser.y"
					{
						t.add_level();
						for (string s : yystack_[2].value.as < std::vector<std::string> >())
							t.add_local(s, "unknown");
					}
#line 1398 "y.tab.cpp"
					break;

					case 18:
#line 402 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();

						reverse(yystack_[4].value.as < std::vector<rapidjson::Document *> >().begin(), yystack_[4].value.as < std::vector<rapidjson::Document *> >().end());

						Document d;
						d.SetArray();
						auto& alloc = d.GetAllocator();
						Value json_val;

						for (string s : yystack_[6].value.as < std::vector<std::string> >())
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
						for (Document *e : yystack_[4].value.as < std::vector<rapidjson::Document *> >())
							de.PushBack(*e, alloce);
						json_val.CopyFrom(de, for_allocator);
						ford->AddMember("expressions_list", json_val, for_allocator);
						json_val.CopyFrom(*yystack_[1].value.as < rapidjson::Document * >(), for_allocator);
						ford->AddMember("block", json_val, for_allocator);

						json_val.CopyFrom(*ford, allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("foreach", json_val, allocator);

						t.delete_level();
					}
#line 1450 "y.tab.cpp"
					break;

					case 19:
#line 451 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						Value json_val;

						Document *fd = new Document();
						fd->SetObject();
						auto& f_allocator = fd->GetAllocator();

						json_val.CopyFrom(*yystack_[1].value.as < rapidjson::Document * >(), f_allocator);
						fd->AddMember("name", json_val, f_allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), f_allocator);
						fd->AddMember("body", json_val, f_allocator);

						json_val.CopyFrom(*fd, allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("function_definition", json_val, allocator);
					}
#line 1473 "y.tab.cpp"
					break;

					case 20:
#line 471 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();

						Document *fd = new Document();
						fd->SetObject();
						auto& f_allocator = fd->GetAllocator();

						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), f_allocator);
						fd->AddMember("name", json_val, f_allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), f_allocator);
						fd->AddMember("body", json_val, f_allocator);

						json_val.CopyFrom(*fd, allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("local_function_definition", json_val, allocator);
					}
#line 1496 "y.tab.cpp"
					break;

					case 21:
#line 491 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetArray();
						auto& alloc = yylhs.value.as < rapidjson::Document * >()->GetAllocator();

						for (int i = 0; i < min(yystack_[1].value.as < std::vector<std::string> >().size(), yystack_[0].value.as < std::vector<rapidjson::Document *> >().size()); i++)
						{
							Document *d = new Document();
							d->SetObject();
							auto& allocator = d->GetAllocator();
							Value json_val;

							json_val.SetString(yystack_[1].value.as < std::vector<std::string> >()[i].c_str(), allocator);
							d->AddMember("variable_name", json_val, allocator);
							json_val.SetString((*yystack_[0].value.as < std::vector<rapidjson::Document *> >()[i])["type"].GetString(), allocator);
							d->AddMember("type", json_val, allocator);
							json_val.SetUint64(t.add_local(yystack_[1].value.as < std::vector<std::string> >()[i], (*yystack_[0].value.as < std::vector<rapidjson::Document *> >()[i])["type"].GetString()));
							d->AddMember("id", json_val, allocator);
							json_val.CopyFrom(*yystack_[0].value.as < std::vector<rapidjson::Document *> >()[i], allocator);
							d->AddMember("expression", json_val, allocator);
							Document *assigment = new Document();
							assigment->SetObject();
							auto& asg_allocator = assigment->GetAllocator();
							Value asg_json_val;
							asg_json_val.CopyFrom(*d, asg_allocator);
							assigment->AddMember("assigment", asg_json_val, asg_allocator);

							yylhs.value.as < rapidjson::Document * >()->PushBack(*assigment, alloc);
						}
						for (int i = yystack_[0].value.as < std::vector<rapidjson::Document *> >().size(); i < yystack_[1].value.as < std::vector<std::string> >().size(); i++)
						{
							Document *d = new Document();
							d->SetObject();
							auto& allocator = d->GetAllocator();
							Value json_val;
							json_val.SetString(yystack_[1].value.as < std::vector<std::string> >()[i].c_str(), allocator);
							d->AddMember("variable_name", json_val, allocator);
							json_val.SetString("nil", allocator);
							d->AddMember("type", json_val, allocator);
							json_val.SetUint64(t.add_local(yystack_[1].value.as < std::vector<std::string> >()[i], "nil"));
							d->AddMember("id", json_val, allocator);
							Document *assigment = new Document();
							assigment->SetObject();
							auto& asg_allocator = assigment->GetAllocator();
							Value asg_json_val;
							asg_json_val.CopyFrom(*d, asg_allocator);
							assigment->AddMember("assigment", asg_json_val, asg_allocator);

							yylhs.value.as < rapidjson::Document * >()->PushBack(*assigment, alloc);
						}
					}
#line 1552 "y.tab.cpp"
					break;

					case 22:
#line 545 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = yystack_[0].value.as < rapidjson::Document * >();
					}
#line 1560 "y.tab.cpp"
					break;

					case 23:
#line 549 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetDouble(1);
						yylhs.value.as < rapidjson::Document * >()->AddMember("value", json_val, allocator);
						json_val.SetString("double", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
					}
#line 1575 "y.tab.cpp"
					break;

					case 24:
#line 562 "parser.y"
					{
						reverse(yystack_[0].value.as < std::vector<rapidjson::Document *> >().begin(), yystack_[0].value.as < std::vector<rapidjson::Document *> >().end());
						yylhs.value.as < std::vector<rapidjson::Document *> >() = yystack_[0].value.as < std::vector<rapidjson::Document *> >();
					}
#line 1584 "y.tab.cpp"
					break;

					case 25:
#line 566 "parser.y"
					{yylhs.value.as < std::vector<rapidjson::Document *> >() = vector<Document *>(); }
#line 1590 "y.tab.cpp"
					break;

					case 26:
#line 570 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("condition", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("then", json_val, allocator);
					}
#line 1605 "y.tab.cpp"
					break;

					case 27:
#line 583 "parser.y"
					{
						yylhs.value.as < std::vector<rapidjson::Document *> >() = yystack_[0].value.as < std::vector<rapidjson::Document *> >();
						if (!yystack_[1].value.as < rapidjson::Document * >()->ObjectEmpty())
							yylhs.value.as < std::vector<rapidjson::Document *> >().push_back(yystack_[1].value.as < rapidjson::Document * >());
					}
#line 1615 "y.tab.cpp"
					break;

					case 28:
#line 589 "parser.y"
					{yylhs.value.as < std::vector<rapidjson::Document *> >() = vector<Document *>(); }
#line 1621 "y.tab.cpp"
					break;

					case 29:
#line 593 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = yystack_[0].value.as < rapidjson::Document * >();
					}
#line 1629 "y.tab.cpp"
					break;

					case 30:
#line 597 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
					}
#line 1638 "y.tab.cpp"
					break;

					case 31:
#line 604 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						Document doc;
						doc.SetArray();
						auto& alloc = doc.GetAllocator();
						for (Document *d : yystack_[1].value.as < std::vector<rapidjson::Document *> >())
							doc.PushBack(*d, alloc);
						json_val.CopyFrom(doc, allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("return_expressions", json_val, allocator);
					}
#line 1656 "y.tab.cpp"
					break;

					case 32:
#line 619 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("break", json_val, allocator);
					}
#line 1669 "y.tab.cpp"
					break;

					case 33:
#line 628 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
					}
#line 1678 "y.tab.cpp"
					break;

					case 34:
#line 635 "parser.y"
					{
						reverse(yystack_[0].value.as < std::vector<rapidjson::Document *> >().begin(), yystack_[0].value.as < std::vector<rapidjson::Document *> >().end());
						yylhs.value.as < std::vector<rapidjson::Document *> >() = yystack_[0].value.as < std::vector<rapidjson::Document *> >();
					}
#line 1687 "y.tab.cpp"
					break;

					case 35:
#line 640 "parser.y"
					{yylhs.value.as < std::vector<rapidjson::Document *> >() = vector<Document *>(); }
#line 1693 "y.tab.cpp"
					break;

					case 36:
#line 643 "parser.y"
					{ yylhs.value.as < std::string >() = yystack_[0].value.as < std::string >(); }
#line 1699 "y.tab.cpp"
					break;

					case 37:
#line 644 "parser.y"
					{yylhs.value.as < std::string >() = ""; }
#line 1705 "y.tab.cpp"
					break;

					case 38:
#line 648 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						Document d;
						auto& alloc = d.GetAllocator();
						d.SetArray();
						d.PushBack(Value(yystack_[2].value.as < std::string >().c_str(), alloc).Move(), alloc);
						reverse(yystack_[1].value.as < std::vector<std::string> >().begin(), yystack_[1].value.as < std::vector<std::string> >().end());
						Value json_val;
						for (string s : yystack_[1].value.as < std::vector<std::string> >())
							d.PushBack(Value(s.c_str(), alloc).Move(), alloc);
						if (yystack_[0].value.as < std::string >() != "")
						{
							d.PushBack(Value(yystack_[0].value.as < std::string >().c_str(), alloc).Move(), alloc);
							json_val.SetBool(true);
						}
						else
						{
							json_val.SetBool(false);
						}
						yylhs.value.as < rapidjson::Document * >()->AddMember("self_argument", json_val, allocator);
						json_val.CopyFrom(d, allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("function_name", json_val, allocator);
					}
#line 1735 "y.tab.cpp"
					break;

					case 39:
#line 676 "parser.y"
					{
						yylhs.value.as < std::vector<std::string> >() = yystack_[0].value.as < std::vector<std::string> >();
						yylhs.value.as < std::vector<std::string> >().push_back(yystack_[1].value.as < std::string >());
					}
#line 1744 "y.tab.cpp"
					break;

					case 40:
#line 680 "parser.y"
					{yylhs.value.as < std::vector<std::string> >() = vector<string>(); }
#line 1750 "y.tab.cpp"
					break;

					case 41:
#line 684 "parser.y"
					{
						yylhs.value.as < std::string >() = yystack_[0].value.as < std::string >();
					}
#line 1758 "y.tab.cpp"
					break;

					case 42:
#line 687 "parser.y"
					{yylhs.value.as < std::string >() = ""; }
#line 1764 "y.tab.cpp"
					break;

					case 43:
#line 691 "parser.y"
					{
						yylhs.value.as < std::vector<rapidjson::Document *> >() = yystack_[0].value.as < std::vector<rapidjson::Document *> >();
						yylhs.value.as < std::vector<rapidjson::Document *> >().push_back(yystack_[1].value.as < rapidjson::Document * >());
					}
#line 1773 "y.tab.cpp"
					break;

					case 44:
#line 698 "parser.y"
					{
						yylhs.value.as < std::vector<rapidjson::Document *> >() = yystack_[0].value.as < std::vector<rapidjson::Document *> >();
					}
#line 1781 "y.tab.cpp"
					break;

					case 45:
#line 701 "parser.y"
					{yylhs.value.as < std::vector<rapidjson::Document *> >() = vector<Document *>(); }
#line 1787 "y.tab.cpp"
					break;

					case 46:
#line 705 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetString(yystack_[0].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("var_name", json_val, allocator);
					}
#line 1800 "y.tab.cpp"
					break;

					case 47:
#line 715 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[3].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("prefix_expression", json_val, allocator);
						json_val.CopyFrom(*yystack_[1].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("index", json_val, allocator);
					}
#line 1815 "y.tab.cpp"
					break;

					case 48:
#line 727 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[3].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("prefix_expression", json_val, allocator);
						json_val.CopyFrom(*yystack_[1].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("index", json_val, allocator);
					}
#line 1830 "y.tab.cpp"
					break;

					case 49:
#line 739 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[4].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("prefix_expression", json_val, allocator);
						json_val.CopyFrom(*yystack_[1].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("index", json_val, allocator);
					}
#line 1845 "y.tab.cpp"
					break;

					case 50:
#line 751 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("prefix_expression", json_val, allocator);
						json_val.SetString(yystack_[0].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("name", json_val, allocator);
					}
#line 1860 "y.tab.cpp"
					break;

					case 51:
#line 763 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("prefix_expression", json_val, allocator);
						json_val.SetString(yystack_[0].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("name", json_val, allocator);
					}
#line 1875 "y.tab.cpp"
					break;

					case 52:
#line 775 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[3].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("prefix_expression", json_val, allocator);
						json_val.SetString(yystack_[0].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("name", json_val, allocator);
					}
#line 1890 "y.tab.cpp"
					break;

					case 53:
#line 788 "parser.y"
					{
						yylhs.value.as < std::vector<std::string> >() = yystack_[0].value.as < std::vector<std::string> >();
						yylhs.value.as < std::vector<std::string> >().push_back(yystack_[1].value.as < std::string >());
						reverse(yylhs.value.as < std::vector<std::string> >().begin(), yylhs.value.as < std::vector<std::string> >().end());
					}
#line 1900 "y.tab.cpp"
					break;

					case 54:
#line 796 "parser.y"
					{
						yylhs.value.as < std::vector<std::string> >() = yystack_[0].value.as < std::vector<std::string> >();
						yylhs.value.as < std::vector<std::string> >().push_back(yystack_[1].value.as < std::string >());
					}
#line 1909 "y.tab.cpp"
					break;

					case 55:
#line 800 "parser.y"
					{yylhs.value.as < std::vector<std::string> >() = vector<string>(); }
#line 1915 "y.tab.cpp"
					break;

					case 56:
#line 804 "parser.y"
					{
						yylhs.value.as < std::vector<rapidjson::Document *> >() = yystack_[0].value.as < std::vector<rapidjson::Document *> >();
						yylhs.value.as < std::vector<rapidjson::Document *> >().push_back(yystack_[1].value.as < rapidjson::Document * >());
					}
#line 1924 "y.tab.cpp"
					break;

					case 57:
#line 811 "parser.y"
					{
						yylhs.value.as < std::vector<rapidjson::Document *> >() = yystack_[0].value.as < std::vector<rapidjson::Document *> >();
						yylhs.value.as < std::vector<rapidjson::Document *> >().push_back(yystack_[1].value.as < rapidjson::Document * >());
					}
#line 1933 "y.tab.cpp"
					break;

					case 58:
#line 815 "parser.y"
					{yylhs.value.as < std::vector<rapidjson::Document *> >() = vector<Document *>(); }
#line 1939 "y.tab.cpp"
					break;

					case 59:
#line 819 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetString("nil", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString("nil", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("value", json_val, allocator);
					}
#line 1954 "y.tab.cpp"
					break;

					case 60:
#line 831 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetString("boolean", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetBool(false);
						yylhs.value.as < rapidjson::Document * >()->AddMember("value", json_val, allocator);
					}
#line 1969 "y.tab.cpp"
					break;

					case 61:
#line 843 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetString("boolean", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetBool(true);
						yylhs.value.as < rapidjson::Document * >()->AddMember("value", json_val, allocator);
					}
#line 1984 "y.tab.cpp"
					break;

					case 62:
#line 855 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetString("double", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetDouble(yystack_[0].value.as < double >());
						yylhs.value.as < rapidjson::Document * >()->AddMember("value", json_val, allocator);
					}
#line 1999 "y.tab.cpp"
					break;

					case 63:
#line 867 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetString("string", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[0].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("value", json_val, allocator);
					}
#line 2014 "y.tab.cpp"
					break;

					case 64:
#line 879 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetString("dots", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
					}
#line 2027 "y.tab.cpp"
					break;

					case 65:
#line 889 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetString("functiondef", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("value", json_val, allocator);
					}
#line 2042 "y.tab.cpp"
					break;

					case 66:
#line 901 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = yystack_[0].value.as < rapidjson::Document * >();
					}
#line 2050 "y.tab.cpp"
					break;

					case 67:
#line 906 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetString("table", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("value", json_val, allocator);
					}
#line 2065 "y.tab.cpp"
					break;

					case 68:
#line 918 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();
						if (t1 == "double" && t2 == "double")
							json_val.SetString("double", allocator);
						else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
							json_val.SetString("unknown", allocator);
						else
							json_val.SetString("error", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2091 "y.tab.cpp"
					break;

					case 69:
#line 941 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();
						if (t1 == "double" && t2 == "double")
							json_val.SetString("double", allocator);
						else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
							json_val.SetString("unknown", allocator);
						else
							json_val.SetString("error", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2117 "y.tab.cpp"
					break;

					case 70:
#line 964 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();
						if (t1 == "double" && t2 == "double")
							json_val.SetString("double", allocator);
						else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
							json_val.SetString("unknown", allocator);
						else
							json_val.SetString("error", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2143 "y.tab.cpp"
					break;

					case 71:
#line 987 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();
						if (t1 == "double" && t2 == "double")
							json_val.SetString("double", allocator);
						else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
							json_val.SetString("unknown", allocator);
						else
							json_val.SetString("error", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2169 "y.tab.cpp"
					break;

					case 72:
#line 1010 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();
						if (t1 == "double" && t2 == "double")
							json_val.SetString("double", allocator);
						else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
							json_val.SetString("unknown", allocator);
						else
							json_val.SetString("error", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2195 "y.tab.cpp"
					break;

					case 73:
#line 1033 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();

						if (t1 == "double" && t2 == "double")
							json_val.SetString("double", allocator);
						else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
							json_val.SetString("unknown", allocator);
						else
							json_val.SetString("error", allocator);

						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2223 "y.tab.cpp"
					break;

					case 74:
#line 1058 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();

						if ((t1 == "string" || t1 == "double") && (t2 == "string" || t2 == "double"))
							json_val.SetString("string", allocator);
						else if ((t1 == "string" || t1 == "double" || t1 == "unknown") && (t2 == "string" || t2 == "double" || t2 == "unknown"))
							json_val.SetString("unknown", allocator);
						else
							json_val.SetString("error", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2250 "y.tab.cpp"
					break;

					case 75:
#line 1082 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();

						if ((t1 == "double" && t2 == "double") || (t1 == "string" && t2 == "string"))
							json_val.SetString("boolean", allocator);
						else if (t1 == "table" && t2 == "table")
							json_val.SetString("unknown", allocator);
						else
							json_val.SetString("error", allocator);

						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2278 "y.tab.cpp"
					break;

					case 76:
#line 1107 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();

						if ((t1 == "double" && t2 == "double") || (t1 == "string" && t2 == "string"))
							json_val.SetString("boolean", allocator);
						else if (t1 == "table" && t2 == "table")
							json_val.SetString("unknown", allocator);
						else
							json_val.SetString("error", allocator);

						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2306 "y.tab.cpp"
					break;

					case 77:
#line 1132 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();

						if ((t1 == "double" && t2 == "double") || (t1 == "string" && t2 == "string"))
							json_val.SetString("boolean", allocator);
						else if (t1 == "table" && t2 == "table")
							json_val.SetString("unknown", allocator);
						else
							json_val.SetString("error", allocator);

						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2334 "y.tab.cpp"
					break;

					case 78:
#line 1157 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();

						if ((t1 == "double" && t2 == "double") || (t1 == "string" && t2 == "string"))
							json_val.SetString("boolean", allocator);
						else if (t1 == "table" && t2 == "table")
							json_val.SetString("unknown", allocator);
						else
							json_val.SetString("error", allocator);

						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2362 "y.tab.cpp"
					break;

					case 79:
#line 1182 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();

						if (t1 == "error" || t2 == "error")
							json_val.SetString("error", allocator);
						else if (t1 == "table" && t2 == "table")
							json_val.SetString("boolean", allocator);

						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2388 "y.tab.cpp"
					break;

					case 80:
#line 1205 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();

						if (t1 == "error" || t2 == "error")
							json_val.SetString("error", allocator);
						else if (t1 == "table" && t2 == "table")
							json_val.SetString("boolean", allocator);

						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2414 "y.tab.cpp"
					break;

					case 81:
#line 1228 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();

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

						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2448 "y.tab.cpp"
					break;

					case 82:
#line 1259 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string t1 = (*yystack_[2].value.as < rapidjson::Document * >())["type"].GetString();
						string t2 = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();

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

						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("first_argument", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("second_argument", json_val, allocator);
					}
#line 2480 "y.tab.cpp"
					break;

					case 83:
#line 1288 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string tp = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();

						if (tp == "double")
							json_val.SetString("double", allocator);
						else if (tp == "string")
							json_val.SetString("unknown", allocator);
						else
							json_val.SetString("error", allocator);

						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("argument", json_val, allocator);
					}
#line 2505 "y.tab.cpp"
					break;

					case 84:
#line 1310 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string tp = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();

						if (tp == "error")
							json_val.SetString("error", allocator);
						else
							json_val.SetString("boolean", allocator);

						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("argument", json_val, allocator);
					}
#line 2528 "y.tab.cpp"
					break;

					case 85:
#line 1330 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						string tp = (*yystack_[0].value.as < rapidjson::Document * >())["type"].GetString();

						if (tp == "string" || tp == "table")
							json_val.SetString("double", allocator);
						else
							json_val.SetString("error", allocator);

						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("operator", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("argument", json_val, allocator);
					}
#line 2551 "y.tab.cpp"
					break;

					case 86:
#line 1351 "parser.y"
					{
						bool var = yystack_[0].value.as < rapidjson::Document * >()->FindMember("var_name") == yystack_[0].value.as < rapidjson::Document * >()->MemberEnd() ? false : true;
						if (var)
						{
							yylhs.value.as < rapidjson::Document * >() = new Document();
							yylhs.value.as < rapidjson::Document * >()->SetObject();
							Value json_val;
							auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
							json_val.SetString((*yystack_[0].value.as < rapidjson::Document * >())["var_name"].GetString(), allocator);
							yylhs.value.as < rapidjson::Document * >()->AddMember("variable_name", json_val, allocator);
							pair<unsigned long long, string> p = t.get((*yystack_[0].value.as < rapidjson::Document * >())["var_name"].GetString());
							json_val.SetString(p.second.c_str(), allocator);
							yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
							json_val.SetUint64(p.first);
							yylhs.value.as < rapidjson::Document * >()->AddMember("id", json_val, allocator);
						}
						else
						{
							yylhs.value.as < rapidjson::Document * >() = yystack_[0].value.as < rapidjson::Document * >();
							Value json_val;
							auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
							json_val.SetString("unknown", allocator);
							yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
						}
					}
#line 2580 "y.tab.cpp"
					break;

					case 87:
#line 1377 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = yystack_[0].value.as < rapidjson::Document * >();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetString("unknown", allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("type", json_val, allocator);
					}
#line 2592 "y.tab.cpp"
					break;

					case 88:
#line 1385 "parser.y"
					{ yylhs.value.as < rapidjson::Document * >() = yystack_[1].value.as < rapidjson::Document * >(); }
#line 2598 "y.tab.cpp"
					break;

					case 89:
#line 1389 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[1].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("prefixexp", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("arguments", json_val, allocator);
					}
#line 2613 "y.tab.cpp"
					break;

					case 90:
#line 1401 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[1].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("prefixexp", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("arguments", json_val, allocator);
					}
#line 2628 "y.tab.cpp"
					break;

					case 91:
#line 1413 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[2].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("prefixexp", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("arguments", json_val, allocator);
					}
#line 2643 "y.tab.cpp"
					break;

					case 92:
#line 1425 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[3].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("prefixexp", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("name", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("arguments", json_val, allocator);
					}
#line 2660 "y.tab.cpp"
					break;

					case 93:
#line 1439 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[3].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("prefixexp", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("name", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("arguments", json_val, allocator);
					}
#line 2677 "y.tab.cpp"
					break;

					case 94:
#line 1453 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[4].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("prefixexp", json_val, allocator);
						json_val.SetString(yystack_[1].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("name", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("arguments", json_val, allocator);
					}
#line 2694 "y.tab.cpp"
					break;

					case 95:
#line 1468 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetArray();
						auto& alloc = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						for (Document *d : yystack_[1].value.as < std::vector<rapidjson::Document *> >())
							yylhs.value.as < rapidjson::Document * >()->PushBack(*d, alloc);
					}
#line 2706 "y.tab.cpp"
					break;

					case 96:
#line 1477 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("table", json_val, allocator);
					}
#line 2719 "y.tab.cpp"
					break;

					case 97:
#line 1487 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetString(yystack_[0].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("string", json_val, allocator);
					}
#line 2732 "y.tab.cpp"
					break;

					case 98:
#line 1498 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("funcbody", json_val, allocator);
					}
#line 2745 "y.tab.cpp"
					break;

					case 99:
#line 1508 "parser.y"
					{t.add_level(); }
#line 2751 "y.tab.cpp"
					break;

					case 100:
#line 1509 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[3].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("parlist", json_val, allocator);
						json_val.CopyFrom(*yystack_[1].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("block", json_val, allocator);
						t.delete_level();
					}
#line 2767 "y.tab.cpp"
					break;

					case 101:
#line 1523 "parser.y"
					{
						Document d;
						auto& alloc = d.GetAllocator();
						d.SetArray();
						for (string s : yystack_[1].value.as < std::vector<std::string> >())
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

						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(d, allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("namelist", json_val, allocator);
						json_val.SetBool(yystack_[0].value.as < bool >());
						yylhs.value.as < rapidjson::Document * >()->AddMember("dots", json_val, allocator);
					}
#line 2800 "y.tab.cpp"
					break;

					case 102:
#line 1553 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetBool(true);
						yylhs.value.as < rapidjson::Document * >()->AddMember("dots", json_val, allocator);
					}
#line 2813 "y.tab.cpp"
					break;

					case 103:
#line 1562 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetBool(false);
						yylhs.value.as < rapidjson::Document * >()->AddMember("dots", json_val, allocator);
					}
#line 2826 "y.tab.cpp"
					break;

					case 104:
#line 1573 "parser.y"
					{
						yylhs.value.as < bool >() = true;
					}
#line 2834 "y.tab.cpp"
					break;

					case 105:
#line 1577 "parser.y"
					{
						yylhs.value.as < bool >() = false;
					}
#line 2842 "y.tab.cpp"
					break;

					case 106:
#line 1583 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[1].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("fieldlist", json_val, allocator);
					}
#line 2855 "y.tab.cpp"
					break;

					case 107:
#line 1594 "parser.y"
					{
						yystack_[1].value.as < std::vector<rapidjson::Document *> >().push_back(yystack_[2].value.as < rapidjson::Document * >());
						reverse(yystack_[1].value.as < std::vector<rapidjson::Document *> >().begin(), yystack_[1].value.as < std::vector<rapidjson::Document *> >().end());
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetArray();
						auto& alloc = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						for (Document *d : yystack_[1].value.as < std::vector<rapidjson::Document *> >())
						{
							yylhs.value.as < rapidjson::Document * >()->PushBack(*d, alloc);
						}
					}
#line 2871 "y.tab.cpp"
					break;

					case 108:
#line 1606 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
					}
#line 2880 "y.tab.cpp"
					break;

					case 109:
#line 1613 "parser.y"
					{
						yylhs.value.as < std::vector<rapidjson::Document *> >() = yystack_[0].value.as < std::vector<rapidjson::Document *> >();
						yylhs.value.as < std::vector<rapidjson::Document *> >().push_back(yystack_[1].value.as < rapidjson::Document * >());
					}
#line 2889 "y.tab.cpp"
					break;

					case 110:
#line 1617 "parser.y"
					{yylhs.value.as < std::vector<rapidjson::Document *> >() = vector<Document *>(); }
#line 2895 "y.tab.cpp"
					break;

					case 111:
#line 1620 "parser.y"
					{ yylhs.value.as < std::string >() = yystack_[0].value.as < std::string >(); }
#line 2901 "y.tab.cpp"
					break;

					case 112:
#line 1621 "parser.y"
					{yylhs.value.as < std::string >() = ""; }
#line 2907 "y.tab.cpp"
					break;

					case 113:
#line 1625 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[3].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("left_expression", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("right_expression", json_val, allocator);
					}
#line 2922 "y.tab.cpp"
					break;

					case 114:
#line 1637 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.SetString(yystack_[2].value.as < std::string >().c_str(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("left_name", json_val, allocator);
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("right_expression", json_val, allocator);
					}
#line 2937 "y.tab.cpp"
					break;

					case 115:
#line 1649 "parser.y"
					{
						yylhs.value.as < rapidjson::Document * >() = new Document();
						yylhs.value.as < rapidjson::Document * >()->SetObject();
						Value json_val;
						auto& allocator = yylhs.value.as < rapidjson::Document * >()->GetAllocator();
						json_val.CopyFrom(*yystack_[0].value.as < rapidjson::Document * >(), allocator);
						yylhs.value.as < rapidjson::Document * >()->AddMember("expression", json_val, allocator);
					}
#line 2950 "y.tab.cpp"
					break;

					case 116:
#line 1659 "parser.y"
					{ yylhs.value.as < std::string >() = yystack_[0].value.as < std::string >(); }
#line 2956 "y.tab.cpp"
					break;

					case 117:
#line 1661 "parser.y"
					{ yylhs.value.as < std::string >() = yystack_[0].value.as < std::string >(); }
#line 2962 "y.tab.cpp"
					break;


#line 2966 "y.tab.cpp"

					default:
						break;
					}
				}
#if YY_EXCEPTIONS
				catch (const syntax_error& yyexc)
				{
					YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
					error(yyexc);
					YYERROR;
				}
#endif // YY_EXCEPTIONS
				YY_SYMBOL_PRINT("-> $$ =", yylhs);
				yypop_(yylen);
				yylen = 0;
				YY_STACK_PRINT();

				// Shift the result of the reduction.
				yypush_(YY_NULLPTR, YY_MOVE(yylhs));
			}
			goto yynewstate;


			/*--------------------------------------.
			| yyerrlab -- here on detecting error.  |
			`--------------------------------------*/
		yyerrlab:
			// If not already recovering from an error, report this error.
			if (!yyerrstatus_)
			{
				++yynerrs_;
				error(yysyntax_error_(yystack_[0].state, yyla));
			}


			if (yyerrstatus_ == 3)
			{
				/* If just tried and failed to reuse lookahead token after an
				   error, discard it.  */

				   // Return failure if at end of input.
				if (yyla.type_get() == yyeof_)
					YYABORT;
				else if (!yyla.empty())
				{
					yy_destroy_("Error: discarding", yyla);
					yyla.clear();
				}
			}

			// Else will try to reuse lookahead token after shifting the error token.
			goto yyerrlab1;


			/*---------------------------------------------------.
			| yyerrorlab -- error raised explicitly by YYERROR.  |
			`---------------------------------------------------*/
		yyerrorlab:
			/* Pacify compilers when the user code never invokes YYERROR and
			   the label yyerrorlab therefore never appears in user code.  */
			if (false)
				YYERROR;

			/* Do not reclaim the symbols of the rule whose action triggered
			   this YYERROR.  */
			yypop_(yylen);
			yylen = 0;
			goto yyerrlab1;


			/*-------------------------------------------------------------.
			| yyerrlab1 -- common code for both syntax error and YYERROR.  |
			`-------------------------------------------------------------*/
		yyerrlab1:
			yyerrstatus_ = 3;   // Each real token shifted decrements this.
			{
				stack_symbol_type error_token;
				for (;;)
				{
					yyn = yypact_[yystack_[0].state];
					if (!yy_pact_value_is_default_(yyn))
					{
						yyn += yy_error_token_;
						if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
						{
							yyn = yytable_[yyn];
							if (0 < yyn)
								break;
						}
					}

					// Pop the current state because it cannot handle the error token.
					if (yystack_.size() == 1)
						YYABORT;

					yy_destroy_("Error: popping", yystack_[0]);
					yypop_();
					YY_STACK_PRINT();
				}


				// Shift the error token.
				error_token.state = static_cast<state_type> (yyn);
				yypush_("Shifting", YY_MOVE(error_token));
			}
			goto yynewstate;


			/*-------------------------------------.
			| yyacceptlab -- YYACCEPT comes here.  |
			`-------------------------------------*/
		yyacceptlab:
			yyresult = 0;
			goto yyreturn;


			/*-----------------------------------.
			| yyabortlab -- YYABORT comes here.  |
			`-----------------------------------*/
		yyabortlab:
			yyresult = 1;
			goto yyreturn;


			/*-----------------------------------------------------.
			| yyreturn -- parsing is finished, return the result.  |
			`-----------------------------------------------------*/
		yyreturn:
			if (!yyla.empty())
				yy_destroy_("Cleanup: discarding lookahead", yyla);

			/* Do not reclaim the symbols of the rule whose action triggered
			   this YYABORT or YYACCEPT.  */
			yypop_(yylen);
			while (1 < yystack_.size())
			{
				yy_destroy_("Cleanup: popping", yystack_[0]);
				yypop_();
			}

			return yyresult;
		}
#if YY_EXCEPTIONS
		catch (...)
		{
			YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
			// Do not try to display the values of the reclaimed symbols,
			// as their printers might throw an exception.
			if (!yyla.empty())
				yy_destroy_(YY_NULLPTR, yyla);

			while (1 < yystack_.size())
			{
				yy_destroy_(YY_NULLPTR, yystack_[0]);
				yypop_();
			}
			throw;
		}
#endif // YY_EXCEPTIONS
	}

	void
		parser::error(const syntax_error& yyexc)
	{
		error(yyexc.what());
	}

	// Generate an error message.
	std::string
		parser::yysyntax_error_(state_type yystate, const symbol_type& yyla) const
	{
		// Number of reported tokens (one for the "unexpected", one per
		// "expected").
		std::ptrdiff_t yycount = 0;
		// Its maximum.
		enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
		// Arguments of yyformat.
		char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

		/* There are many possibilities here to consider:
		   - If this state is a consistent state with a default action, then
			 the only way this function was invoked is if the default action
			 is an error action.  In that case, don't check for expected
			 tokens because there are none.
		   - The only way there can be no lookahead present (in yyla) is
			 if this state is a consistent state with a default action.
			 Thus, detecting the absence of a lookahead is sufficient to
			 determine that there is no unexpected or expected token to
			 report.  In that case, just report a simple "syntax error".
		   - Don't assume there isn't a lookahead just because this state is
			 a consistent state with a default action.  There might have
			 been a previous inconsistent state, consistent state with a
			 non-default action, or user semantic action that manipulated
			 yyla.  (However, yyla is currently not documented for users.)
		   - Of course, the expected token list depends on states to have
			 correct lookahead information, and it depends on the parser not
			 to perform extra reductions after fetching a lookahead from the
			 scanner and before detecting a syntax error.  Thus, state merging
			 (from LALR or IELR) and default reductions corrupt the expected
			 token list.  However, the list is correct for canonical LR with
			 one exception: it will still contain any token that will not be
			 accepted due to an error action in a later state.
		*/
		if (!yyla.empty())
		{
			symbol_number_type yytoken = yyla.type_get();
			yyarg[yycount++] = yytname_[yytoken];

			int yyn = yypact_[yystate];
			if (!yy_pact_value_is_default_(yyn))
			{
				/* Start YYX at -YYN if negative to avoid negative indexes in
				   YYCHECK.  In other words, skip the first -YYN actions for
				   this state because they are default actions.  */
				int yyxbegin = yyn < 0 ? -yyn : 0;
				// Stay within bounds of both yycheck and yytname.
				int yychecklim = yylast_ - yyn + 1;
				int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
				for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
					if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
						&& !yy_table_value_is_error_(yytable_[yyx + yyn]))
					{
						if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
						{
							yycount = 1;
							break;
						}
						else
							yyarg[yycount++] = yytname_[yyx];
					}
			}
		}

		char const* yyformat = YY_NULLPTR;
		switch (yycount)
		{
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
		default: // Avoid compiler warnings.
			YYCASE_(0, YY_("syntax error"));
			YYCASE_(1, YY_("syntax error, unexpected %s"));
			YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
			YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
			YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
			YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
		}

		std::string yyres;
		// Argument number.
		std::ptrdiff_t yyi = 0;
		for (char const* yyp = yyformat; *yyp; ++yyp)
			if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
			{
				yyres += yytnamerr_(yyarg[yyi++]);
				++yyp;
			}
			else
				yyres += *yyp;
		return yyres;
	}


	const signed char parser::yypact_ninf_ = -52;

	const signed char parser::yytable_ninf_ = -4;

	const short
		parser::yypact_[] =
	{
		 8,    10,   -52,    40,   -52,   -52,   -52,    21,    23,   189,
		36,   -52,   189,    40,   189,    11,    40,    -2,   110,   135,
		28,   -16,    33,    20,   -52,   -52,   -52,   -52,   -52,   -52,
	   -52,   -52,   189,   130,   189,   189,   189,   192,   226,   -52,
	   135,   -52,   -52,    27,    38,    30,    44,   210,   -52,   267,
		42,   189,   -52,   -52,   189,   -52,    62,   189,   189,     4,
		77,   -52,   -52,   -52,    80,   189,    81,   -52,   -52,   189,
		97,   -52,   189,    99,    82,   -52,    79,   -52,   289,    83,
	   189,   435,    76,    22,   -52,   -52,   -52,   -52,   189,   189,
	   189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
	   189,   189,   189,   -52,   189,   -52,   189,   -52,   204,   -52,
	   -52,    42,   -52,   386,   -52,    14,    85,   309,   -52,   135,
	   -52,    14,   329,   -52,   403,    27,   -52,    20,   111,   -52,
		13,   204,   189,   349,   -52,   -52,   -52,    22,   130,   116,
	   449,   462,   469,   469,   469,   469,   469,   469,    24,    55,
		55,    65,    65,    65,   -52,   -52,   -52,   435,   117,   115,
	   189,   121,   -52,   -52,   189,   -52,   -52,   -52,   -52,   -52,
	   -52,   189,   -52,   122,   -52,   -52,   -52,    92,   101,   435,
	   108,   -52,   -52,    22,   189,   116,   124,   -52,    14,   369,
	   -52,   386,   420,   -52,   126,   -52,   -52,   189,   -52,   245,
	   -52,   -52,   142,   -52,   -52,   -52,   189,   -52,   143,   -52,
	   147,   435,   -52,   -52,   -52,   435,   138,   -52,   -52,   -52,
	   -52,   148,   -52
	};

	const signed char
		parser::yydefact_[] =
	{
		 4,     0,     2,     8,     1,    46,     4,     0,     0,     0,
		 0,     4,     0,     8,     0,    33,     8,     0,    45,    10,
		 0,    55,     0,    40,    99,    60,    99,    59,    61,    64,
		62,    63,     0,   108,     0,     0,     0,    86,     0,    66,
		87,    65,    67,    55,     0,    25,     0,     0,     7,     0,
		37,    35,     5,     6,     0,    97,     0,    35,     0,     0,
		 0,    43,    89,    96,     0,     0,     0,    90,    11,     0,
		 0,    53,     0,     0,    42,    19,     0,    98,     0,    46,
		 0,   115,     0,   110,    83,    84,    85,     4,     0,     0,
		 0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
		 0,     0,     0,    99,     0,    21,     0,     4,     0,    36,
		32,    37,    34,    58,     9,     0,     0,     0,    44,     0,
		50,     0,     0,    51,     0,    55,    17,    40,     0,    38,
	   103,    88,     0,     0,   106,   117,   116,   112,     0,    28,
		82,    81,    75,    77,    78,    76,    79,    80,    74,    68,
		69,    70,    71,    73,    72,    20,    24,    13,     0,     0,
		 0,     0,    91,    31,     0,    56,    92,    95,    47,    93,
		48,     0,    54,     0,    39,    41,   102,   105,     0,   114,
		 0,   107,   111,   110,     0,    28,    30,    12,     0,     0,
		52,    58,    23,     4,     0,   101,     4,     0,   109,     0,
		27,     4,     0,    94,    49,    57,     0,    15,     0,   104,
		 0,   113,     4,    29,    14,    22,     0,    18,   100,    26,
		 4,     0,    16
	};

	const signed char
		parser::yypgoto_[] =
	{
	   -52,   -52,    -6,   -52,    66,   -52,   -52,   -52,   -52,   -52,
	   -52,   -27,   -52,   -52,   109,    59,   -52,    46,   -52,   112,
	   -52,     1,    -8,    49,   -51,   -15,    -3,   -52,     9,     5,
	   -52,   -25,   -52,   -52,   -52,     0,   -52,    -4,   -52,    37,
		43
	};

	const short
		parser::yydefgoto_[] =
	{
		-1,     1,     2,     3,    15,    16,   216,   173,   207,   105,
	   185,   186,   202,    52,   111,   110,    24,    74,   129,    17,
		61,    37,    22,    71,   112,   165,   113,    39,    40,    67,
		41,    75,    76,   178,   195,    42,    82,   137,   181,    83,
	   138
	};

	const short
		parser::yytable_[] =
	{
		20,    77,    45,   114,    18,    46,    38,     5,    -3,    47,
		 4,    49,    19,    69,    18,    50,    43,    18,    63,    63,
		70,   126,    19,    62,    21,    19,    23,    54,    51,    78,
		81,    84,    85,    86,    14,   176,    68,    63,    55,    43,
		63,   103,    62,     5,    57,     6,    72,    44,    33,   135,
		 7,     8,     9,   156,    10,   117,    11,    73,   136,   104,
		18,    12,   122,    70,   106,   115,   124,    13,   119,   109,
		14,    97,    98,    99,   100,   101,   102,   133,   155,    48,
	   120,   139,    53,   121,   123,   140,   141,   142,   143,   144,
	   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
	   125,   158,   127,   157,    99,   100,   101,   102,    63,   130,
	   128,   134,   132,   162,   175,    63,   167,   102,   188,    63,
	   166,    63,   177,   184,   190,   187,   169,   193,   194,   179,
	   201,    63,   196,    79,    55,    81,   162,   197,    56,    25,
		57,    26,    58,   220,    33,    27,    59,    60,   209,    28,
	   214,   217,    29,    30,    31,   218,   222,   189,   200,    55,
		32,   191,    80,    64,    33,    57,   116,    65,   192,    33,
	   163,   118,    66,   174,   172,   183,   205,     0,    34,   198,
	   182,   199,     0,    35,    36,     0,     0,   208,    63,     0,
	   210,     0,     5,   203,   211,   213,     0,     0,    25,     0,
		26,     0,     0,   215,    27,     0,   219,     0,    28,     0,
		 0,    29,    30,    31,   221,   107,    55,     0,     0,    32,
		56,     0,    57,    33,    58,     0,    33,     0,    55,    60,
		 0,     0,   159,     0,    57,     0,   160,    34,    33,     0,
		 0,   161,    35,    36,    87,     0,     0,     0,    88,    89,
		90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
	   100,   101,   102,   212,    88,    89,    90,    91,    92,    93,
		94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
		 0,     0,     0,    88,    89,    90,    91,    92,    93,    94,
		95,    96,    97,    98,    99,   100,   101,   102,   108,     0,
		 0,     0,     0,     0,     0,    88,    89,    90,    91,    92,
		93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
	   131,     0,     0,     0,     0,     0,     0,    88,    89,    90,
		91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
	   101,   102,   168,     0,     0,     0,     0,    88,    89,    90,
		91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
	   101,   102,   170,     0,     0,     0,     0,    88,    89,    90,
		91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
	   101,   102,   180,     0,     0,     0,     0,    88,    89,    90,
		91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
	   101,   102,   204,     0,     0,     0,     0,    88,    89,    90,
		91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
	   101,   102,   164,     0,    88,    89,    90,    91,    92,    93,
		94,    95,    96,    97,    98,    99,   100,   101,   102,   171,
		 0,    88,    89,    90,    91,    92,    93,    94,    95,    96,
		97,    98,    99,   100,   101,   102,   206,     0,    88,    89,
		90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
	   100,   101,   102,    88,    89,    90,    91,    92,    93,    94,
		95,    96,    97,    98,    99,   100,   101,   102,    89,    90,
		91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
	   101,   102,    90,    91,    92,    93,    94,    95,    96,    97,
		98,    99,   100,   101,   102,    96,    97,    98,    99,   100,
	   101,   102
	};

	const short
		parser::yycheck_[] =
	{
		 6,    26,    10,    54,     3,    11,     9,     3,     0,    12,
		 0,    14,     3,    29,    13,     4,     3,    16,    18,    19,
		36,    72,    13,    18,     3,    16,     3,    29,    17,    32,
		33,    34,    35,    36,    30,    22,     8,    37,    24,     3,
		40,     3,    37,     3,    30,     5,    13,    11,    34,    27,
		10,    11,    12,   104,    14,    58,    16,    37,    36,    29,
		59,    21,    65,    36,    20,     3,    69,    27,    59,    27,
		30,    47,    48,    49,    50,    51,    52,    80,   103,    13,
		 3,    87,    16,     3,     3,    88,    89,    90,    91,    92,
		93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
		 3,   107,     3,   106,    49,    50,    51,    52,   108,    30,
		28,    35,    29,   108,     3,   115,    31,    52,     3,   119,
	   115,   121,   130,     7,     3,     8,   121,     5,    36,   132,
		 6,   131,    31,     3,    24,   138,   131,    29,    28,     9,
		30,    11,    32,     5,    34,    15,    36,    37,    22,    19,
		 8,     8,    22,    23,    24,     8,     8,   160,   185,    24,
		30,   164,    32,    28,    34,    30,    57,    32,   171,    34,
	   111,    59,    37,   127,   125,   138,   191,    -1,    48,   183,
	   137,   184,    -1,    53,    54,    -1,    -1,   193,   188,    -1,
	   196,    -1,     3,   188,   197,   201,    -1,    -1,     9,    -1,
		11,    -1,    -1,   206,    15,    -1,   212,    -1,    19,    -1,
		-1,    22,    23,    24,   220,     5,    24,    -1,    -1,    30,
		28,    -1,    30,    34,    32,    -1,    34,    -1,    24,    37,
		-1,    -1,    28,    -1,    30,    -1,    32,    48,    34,    -1,
		-1,    37,    53,    54,    18,    -1,    -1,    -1,    38,    39,
		40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
		50,    51,    52,    18,    38,    39,    40,    41,    42,    43,
		44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
		-1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
		45,    46,    47,    48,    49,    50,    51,    52,    31,    -1,
		-1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
		43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
		31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
		41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
		51,    52,    33,    -1,    -1,    -1,    -1,    38,    39,    40,
		41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
		51,    52,    33,    -1,    -1,    -1,    -1,    38,    39,    40,
		41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
		51,    52,    33,    -1,    -1,    -1,    -1,    38,    39,    40,
		41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
		51,    52,    33,    -1,    -1,    -1,    -1,    38,    39,    40,
		41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
		51,    52,    36,    -1,    38,    39,    40,    41,    42,    43,
		44,    45,    46,    47,    48,    49,    50,    51,    52,    36,
		-1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
		47,    48,    49,    50,    51,    52,    36,    -1,    38,    39,
		40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
		50,    51,    52,    38,    39,    40,    41,    42,    43,    44,
		45,    46,    47,    48,    49,    50,    51,    52,    39,    40,
		41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
		51,    52,    40,    41,    42,    43,    44,    45,    46,    47,
		48,    49,    50,    51,    52,    46,    47,    48,    49,    50,
		51,    52
	};

	const signed char
		parser::yystos_[] =
	{
		 0,    57,    58,    59,     0,     3,     5,    10,    11,    12,
		14,    16,    21,    27,    30,    60,    61,    75,    77,    84,
		58,     3,    78,     3,    72,     9,    11,    15,    19,    22,
		23,    24,    30,    34,    48,    53,    54,    77,    82,    83,
		84,    86,    91,     3,    11,    78,    58,    82,    60,    82,
		 4,    17,    69,    60,    29,    24,    28,    30,    32,    36,
		37,    76,    85,    91,    28,    32,    37,    85,     8,    29,
		36,    79,    13,    37,    73,    87,    88,    87,    82,     3,
		32,    82,    92,    95,    82,    82,    82,    18,    38,    39,
		40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
		50,    51,    52,     3,    29,    65,    20,     5,    31,    27,
		71,    70,    80,    82,    80,     3,    70,    82,    75,    84,
		 3,     3,    82,     3,    82,     3,    80,     3,    28,    74,
		30,    31,    29,    82,    35,    27,    36,    93,    96,    58,
		82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
		82,    82,    82,    82,    82,    87,    80,    82,    58,    28,
		32,    37,    85,    71,    36,    81,    85,    31,    33,    85,
		33,    36,    79,    63,    73,     3,    22,    78,    89,    82,
		33,    94,    96,    95,     7,    66,    67,     8,     3,    82,
		 3,    82,    82,     5,    36,    90,    31,    29,    93,    82,
		67,     6,    68,    85,    33,    81,    36,    64,    58,    22,
		58,    82,    18,    58,     8,    82,    62,     8,     8,    58,
		 5,    58,     8
	};

	const signed char
		parser::yyr1_[] =
	{
		 0,    56,    57,    57,    59,    58,    60,    60,    60,    61,
		61,    61,    61,    61,    61,    62,    61,    63,    61,    61,
		61,    61,    64,    64,    65,    65,    66,    67,    67,    68,
		68,    69,    69,    69,    70,    70,    71,    71,    72,    73,
		73,    74,    74,    75,    76,    76,    77,    77,    77,    77,
		77,    77,    77,    78,    79,    79,    80,    81,    81,    82,
		82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
		82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
		82,    82,    82,    82,    82,    82,    83,    83,    83,    84,
		84,    84,    84,    84,    84,    85,    85,    85,    86,    88,
		87,    89,    89,    89,    90,    90,    91,    92,    92,    93,
		93,    94,    94,    95,    95,    95,    96,    96
	};

	const signed char
		parser::yyr2_[] =
	{
		 0,     2,     1,     0,     0,     3,     2,     2,     0,     3,
		 1,     3,     5,     4,     7,     0,    11,     0,     8,     3,
		 4,     3,     2,     0,     2,     0,     4,     2,     0,     2,
		 0,     3,     2,     0,     1,     0,     1,     0,     3,     3,
		 0,     2,     0,     2,     2,     0,     1,     4,     4,     6,
		 3,     3,     5,     2,     3,     0,     2,     3,     0,     1,
		 1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
		 3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
		 3,     3,     3,     2,     2,     2,     1,     1,     3,     2,
		 2,     4,     4,     4,     6,     3,     1,     1,     2,     0,
		 6,     2,     1,     0,     2,     0,     3,     3,     0,     3,
		 0,     1,     0,     5,     3,     1,     1,     1
	};



	// YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
	// First, the terminals, then, starting at \a yyntokens_, nonterminals.
	const char*
		const parser::yytname_[] =
	{
	"\"end of file\"", "error", "$undefined", "TK_NAME", "TK_BREAK",
	"TK_DO", "TK_ELSE", "TK_ELSEIF", "TK_END", "TK_FALSE", "TK_FOR",
	"TK_FUNCTION", "TK_IF", "TK_IN", "TK_LOCAL", "TK_NIL", "TK_REPEAT",
	"TK_RETURN", "TK_THEN", "TK_TRUE", "TK_UNTIL", "TK_WHILE", "TK_DOTS",
	"TK_NUMBER", "TK_STRING", "TK_WHITESPACE", "TK_BADCHAR", "TK_SEMICOLON",
	"TK_COLON", "TK_UEQ", "TK_LB", "TK_RB", "TK_LKB", "TK_RKB", "TK_LFB",
	"TK_RFB", "TK_COMMA", "TK_DOT", "TK_OR", "TK_AND", "TK_LT", "TK_GR",
	"TK_GE", "TK_LE", "TK_EQ", "TK_NE", "TK_CONCAT", "TK_PLUS", "TK_MINUS",
	"TK_MUL", "TK_DIV", "TK_PREC", "TK_CARET", "TK_NOT", "TK_HASH", "UMINUS",
	"$accept", "program", "block", "$@1", "opstat", "stat", "$@2", "$@3",
	"forstep", "eqexplist", "elseif", "elseifs", "else", "retstat",
	"opexplist", "opsemicolon", "funcname", "dotnames", "colonname",
	"varlist", "commavar", "var", "namelist", "commanames", "explist",
	"commaexps", "exp", "prefixexp", "functioncall", "args", "functiondef",
	"funcbody", "$@4", "parlist", "opcommadots", "tableconstructor",
	"fieldlist", "opsepfields", "opsep", "field", "fieldsep", YY_NULLPTR
	};

#if YYDEBUG
	const short
		parser::yyrline_[] =
	{
		 0,   126,   126,   132,   139,   139,   169,   175,   179,   182,
	   256,   266,   271,   290,   309,   345,   344,   396,   395,   450,
	   470,   490,   544,   549,   561,   566,   569,   582,   589,   592,
	   597,   603,   618,   628,   634,   640,   643,   644,   647,   675,
	   680,   683,   687,   690,   697,   701,   704,   714,   726,   738,
	   750,   762,   774,   787,   795,   800,   803,   810,   815,   818,
	   830,   842,   854,   866,   878,   888,   900,   905,   917,   940,
	   963,   986,  1009,  1032,  1057,  1081,  1106,  1131,  1156,  1181,
	  1204,  1227,  1258,  1287,  1309,  1329,  1350,  1376,  1385,  1388,
	  1400,  1412,  1424,  1438,  1452,  1467,  1476,  1486,  1497,  1508,
	  1508,  1522,  1552,  1562,  1572,  1577,  1582,  1593,  1606,  1612,
	  1617,  1620,  1621,  1624,  1636,  1648,  1659,  1661
	};

	// Print the state stack on the debug stream.
	void
		parser::yystack_print_()
	{
		*yycdebug_ << "Stack now";
		for (stack_type::const_iterator
			i = yystack_.begin(),
			i_end = yystack_.end();
			i != i_end; ++i)
			*yycdebug_ << ' ' << int(i->state);
		*yycdebug_ << '\n';
	}

	// Report on the debug stream that the rule \a yyrule is going to be reduced.
	void
		parser::yy_reduce_print_(int yyrule)
	{
		int yylno = yyrline_[yyrule];
		int yynrhs = yyr2_[yyrule];
		// Print the symbols being reduced, and their result.
		*yycdebug_ << "Reducing stack by rule " << yyrule - 1
			<< " (line " << yylno << "):\n";
		// The symbols being reduced.
		for (int yyi = 0; yyi < yynrhs; yyi++)
			YY_SYMBOL_PRINT("   $" << yyi + 1 << " =",
				yystack_[(yynrhs)-(yyi + 1)]);
	}
#endif // YYDEBUG


} // yy
#line 3565 "y.tab.cpp"

#line 1664 "parser.y"


void yy::parser::error(const std::string& err) {
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
