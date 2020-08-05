// A Bison parser, made by GNU Bison 3.5.0.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file y.tab.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
// "%code requires" blocks.
#line 13 "parser.y"

#include "globals.h"
#include "variable.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"

#line 55 "y.tab.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif


#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 189 "y.tab.hpp"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // opcommadots
      char dummy1[sizeof (bool)];

      // TK_NUMBER
      char dummy2[sizeof (double)];

      // program
      // block
      // stat
      // forstep
      // elseif
      // else
      // retstat
      // funcname
      // var
      // exp
      // prefixexp
      // functioncall
      // args
      // functiondef
      // funcbody
      // parlist
      // tableconstructor
      // fieldlist
      // field
      char dummy3[sizeof (rapidjson::Document *)];

      // TK_NAME
      // TK_BREAK
      // TK_DO
      // TK_ELSE
      // TK_ELSEIF
      // TK_END
      // TK_FALSE
      // TK_FOR
      // TK_FUNCTION
      // TK_IF
      // TK_IN
      // TK_LOCAL
      // TK_NIL
      // TK_REPEAT
      // TK_RETURN
      // TK_THEN
      // TK_TRUE
      // TK_UNTIL
      // TK_WHILE
      // TK_DOTS
      // TK_STRING
      // TK_WHITESPACE
      // TK_BADCHAR
      // TK_SEMICOLON
      // TK_COLON
      // TK_UEQ
      // TK_LB
      // TK_RB
      // TK_LKB
      // TK_RKB
      // TK_LFB
      // TK_RFB
      // TK_COMMA
      // TK_DOT
      // TK_OR
      // TK_AND
      // TK_LT
      // TK_GR
      // TK_GE
      // TK_LE
      // TK_EQ
      // TK_NE
      // TK_CONCAT
      // TK_PLUS
      // TK_MINUS
      // TK_MUL
      // TK_DIV
      // TK_PREC
      // TK_CARET
      // TK_NOT
      // TK_HASH
      // opsemicolon
      // colonname
      // opsep
      // fieldsep
      char dummy4[sizeof (std::string)];

      // opstat
      // eqexplist
      // elseifs
      // opexplist
      // varlist
      // commavar
      // explist
      // commaexps
      // opsepfields
      char dummy5[sizeof (std::vector<rapidjson::Document *>)];

      // dotnames
      // namelist
      // commanames
      char dummy6[sizeof (std::vector<std::string>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        QUIT = 0,
        TK_NAME = 258,
        TK_BREAK = 259,
        TK_DO = 260,
        TK_ELSE = 261,
        TK_ELSEIF = 262,
        TK_END = 263,
        TK_FALSE = 264,
        TK_FOR = 265,
        TK_FUNCTION = 266,
        TK_IF = 267,
        TK_IN = 268,
        TK_LOCAL = 269,
        TK_NIL = 270,
        TK_REPEAT = 271,
        TK_RETURN = 272,
        TK_THEN = 273,
        TK_TRUE = 274,
        TK_UNTIL = 275,
        TK_WHILE = 276,
        TK_DOTS = 277,
        TK_NUMBER = 278,
        TK_STRING = 279,
        TK_WHITESPACE = 280,
        TK_BADCHAR = 281,
        TK_SEMICOLON = 282,
        TK_COLON = 283,
        TK_UEQ = 284,
        TK_LB = 285,
        TK_RB = 286,
        TK_LKB = 287,
        TK_RKB = 288,
        TK_LFB = 289,
        TK_RFB = 290,
        TK_COMMA = 291,
        TK_DOT = 292,
        TK_OR = 293,
        TK_AND = 294,
        TK_LT = 295,
        TK_GR = 296,
        TK_GE = 297,
        TK_LE = 298,
        TK_EQ = 299,
        TK_NE = 300,
        TK_CONCAT = 301,
        TK_PLUS = 302,
        TK_MINUS = 303,
        TK_MUL = 304,
        TK_DIV = 305,
        TK_PREC = 306,
        TK_CARET = 307,
        TK_NOT = 308,
        TK_HASH = 309,
        UMINUS = 310
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, double&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const double& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, rapidjson::Document *&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const rapidjson::Document *& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<rapidjson::Document *>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<rapidjson::Document *>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::string>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::string>& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 90: // opcommadots
        value.template destroy< bool > ();
        break;

      case 23: // TK_NUMBER
        value.template destroy< double > ();
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
        value.template destroy< rapidjson::Document * > ();
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
        value.template destroy< std::string > ();
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
        value.template destroy< std::vector<rapidjson::Document *> > ();
        break;

      case 73: // dotnames
      case 78: // namelist
      case 79: // commanames
        value.template destroy< std::vector<std::string> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type(token_type (tok))
      {
        YY_ASSERT (tok == token::QUIT || tok == token::UMINUS);
      }
#else
      symbol_type (int tok)
        : super_type(token_type (tok))
      {
        YY_ASSERT (tok == token::QUIT || tok == token::UMINUS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, double v)
        : super_type(token_type (tok), std::move (v))
      {
        YY_ASSERT (tok == token::TK_NUMBER);
      }
#else
      symbol_type (int tok, const double& v)
        : super_type(token_type (tok), v)
      {
        YY_ASSERT (tok == token::TK_NUMBER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type(token_type (tok), std::move (v))
      {
        YY_ASSERT (tok == token::TK_NAME || tok == token::TK_BREAK || tok == token::TK_DO || tok == token::TK_ELSE || tok == token::TK_ELSEIF || tok == token::TK_END || tok == token::TK_FALSE || tok == token::TK_FOR || tok == token::TK_FUNCTION || tok == token::TK_IF || tok == token::TK_IN || tok == token::TK_LOCAL || tok == token::TK_NIL || tok == token::TK_REPEAT || tok == token::TK_RETURN || tok == token::TK_THEN || tok == token::TK_TRUE || tok == token::TK_UNTIL || tok == token::TK_WHILE || tok == token::TK_DOTS || tok == token::TK_STRING || tok == token::TK_WHITESPACE || tok == token::TK_BADCHAR || tok == token::TK_SEMICOLON || tok == token::TK_COLON || tok == token::TK_UEQ || tok == token::TK_LB || tok == token::TK_RB || tok == token::TK_LKB || tok == token::TK_RKB || tok == token::TK_LFB || tok == token::TK_RFB || tok == token::TK_COMMA || tok == token::TK_DOT || tok == token::TK_OR || tok == token::TK_AND || tok == token::TK_LT || tok == token::TK_GR || tok == token::TK_GE || tok == token::TK_LE || tok == token::TK_EQ || tok == token::TK_NE || tok == token::TK_CONCAT || tok == token::TK_PLUS || tok == token::TK_MINUS || tok == token::TK_MUL || tok == token::TK_DIV || tok == token::TK_PREC || tok == token::TK_CARET || tok == token::TK_NOT || tok == token::TK_HASH);
      }
#else
      symbol_type (int tok, const std::string& v)
        : super_type(token_type (tok), v)
      {
        YY_ASSERT (tok == token::TK_NAME || tok == token::TK_BREAK || tok == token::TK_DO || tok == token::TK_ELSE || tok == token::TK_ELSEIF || tok == token::TK_END || tok == token::TK_FALSE || tok == token::TK_FOR || tok == token::TK_FUNCTION || tok == token::TK_IF || tok == token::TK_IN || tok == token::TK_LOCAL || tok == token::TK_NIL || tok == token::TK_REPEAT || tok == token::TK_RETURN || tok == token::TK_THEN || tok == token::TK_TRUE || tok == token::TK_UNTIL || tok == token::TK_WHILE || tok == token::TK_DOTS || tok == token::TK_STRING || tok == token::TK_WHITESPACE || tok == token::TK_BADCHAR || tok == token::TK_SEMICOLON || tok == token::TK_COLON || tok == token::TK_UEQ || tok == token::TK_LB || tok == token::TK_RB || tok == token::TK_LKB || tok == token::TK_RKB || tok == token::TK_LFB || tok == token::TK_RFB || tok == token::TK_COMMA || tok == token::TK_DOT || tok == token::TK_OR || tok == token::TK_AND || tok == token::TK_LT || tok == token::TK_GR || tok == token::TK_GE || tok == token::TK_LE || tok == token::TK_EQ || tok == token::TK_NE || tok == token::TK_CONCAT || tok == token::TK_PLUS || tok == token::TK_MINUS || tok == token::TK_MUL || tok == token::TK_DIV || tok == token::TK_PREC || tok == token::TK_CARET || tok == token::TK_NOT || tok == token::TK_HASH);
      }
#endif
    };

    /// Build a parser object.
    parser ();
    virtual ~parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUIT ()
      {
        return symbol_type (token::QUIT);
      }
#else
      static
      symbol_type
      make_QUIT ()
      {
        return symbol_type (token::QUIT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_NAME (std::string v)
      {
        return symbol_type (token::TK_NAME, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_NAME (const std::string& v)
      {
        return symbol_type (token::TK_NAME, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_BREAK (std::string v)
      {
        return symbol_type (token::TK_BREAK, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_BREAK (const std::string& v)
      {
        return symbol_type (token::TK_BREAK, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_DO (std::string v)
      {
        return symbol_type (token::TK_DO, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_DO (const std::string& v)
      {
        return symbol_type (token::TK_DO, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_ELSE (std::string v)
      {
        return symbol_type (token::TK_ELSE, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_ELSE (const std::string& v)
      {
        return symbol_type (token::TK_ELSE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_ELSEIF (std::string v)
      {
        return symbol_type (token::TK_ELSEIF, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_ELSEIF (const std::string& v)
      {
        return symbol_type (token::TK_ELSEIF, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_END (std::string v)
      {
        return symbol_type (token::TK_END, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_END (const std::string& v)
      {
        return symbol_type (token::TK_END, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_FALSE (std::string v)
      {
        return symbol_type (token::TK_FALSE, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_FALSE (const std::string& v)
      {
        return symbol_type (token::TK_FALSE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_FOR (std::string v)
      {
        return symbol_type (token::TK_FOR, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_FOR (const std::string& v)
      {
        return symbol_type (token::TK_FOR, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_FUNCTION (std::string v)
      {
        return symbol_type (token::TK_FUNCTION, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_FUNCTION (const std::string& v)
      {
        return symbol_type (token::TK_FUNCTION, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_IF (std::string v)
      {
        return symbol_type (token::TK_IF, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_IF (const std::string& v)
      {
        return symbol_type (token::TK_IF, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_IN (std::string v)
      {
        return symbol_type (token::TK_IN, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_IN (const std::string& v)
      {
        return symbol_type (token::TK_IN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_LOCAL (std::string v)
      {
        return symbol_type (token::TK_LOCAL, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_LOCAL (const std::string& v)
      {
        return symbol_type (token::TK_LOCAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_NIL (std::string v)
      {
        return symbol_type (token::TK_NIL, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_NIL (const std::string& v)
      {
        return symbol_type (token::TK_NIL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_REPEAT (std::string v)
      {
        return symbol_type (token::TK_REPEAT, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_REPEAT (const std::string& v)
      {
        return symbol_type (token::TK_REPEAT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_RETURN (std::string v)
      {
        return symbol_type (token::TK_RETURN, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_RETURN (const std::string& v)
      {
        return symbol_type (token::TK_RETURN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_THEN (std::string v)
      {
        return symbol_type (token::TK_THEN, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_THEN (const std::string& v)
      {
        return symbol_type (token::TK_THEN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_TRUE (std::string v)
      {
        return symbol_type (token::TK_TRUE, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_TRUE (const std::string& v)
      {
        return symbol_type (token::TK_TRUE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_UNTIL (std::string v)
      {
        return symbol_type (token::TK_UNTIL, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_UNTIL (const std::string& v)
      {
        return symbol_type (token::TK_UNTIL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_WHILE (std::string v)
      {
        return symbol_type (token::TK_WHILE, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_WHILE (const std::string& v)
      {
        return symbol_type (token::TK_WHILE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_DOTS (std::string v)
      {
        return symbol_type (token::TK_DOTS, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_DOTS (const std::string& v)
      {
        return symbol_type (token::TK_DOTS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_NUMBER (double v)
      {
        return symbol_type (token::TK_NUMBER, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_NUMBER (const double& v)
      {
        return symbol_type (token::TK_NUMBER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_STRING (std::string v)
      {
        return symbol_type (token::TK_STRING, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_STRING (const std::string& v)
      {
        return symbol_type (token::TK_STRING, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_WHITESPACE (std::string v)
      {
        return symbol_type (token::TK_WHITESPACE, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_WHITESPACE (const std::string& v)
      {
        return symbol_type (token::TK_WHITESPACE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_BADCHAR (std::string v)
      {
        return symbol_type (token::TK_BADCHAR, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_BADCHAR (const std::string& v)
      {
        return symbol_type (token::TK_BADCHAR, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_SEMICOLON (std::string v)
      {
        return symbol_type (token::TK_SEMICOLON, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_SEMICOLON (const std::string& v)
      {
        return symbol_type (token::TK_SEMICOLON, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_COLON (std::string v)
      {
        return symbol_type (token::TK_COLON, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_COLON (const std::string& v)
      {
        return symbol_type (token::TK_COLON, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_UEQ (std::string v)
      {
        return symbol_type (token::TK_UEQ, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_UEQ (const std::string& v)
      {
        return symbol_type (token::TK_UEQ, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_LB (std::string v)
      {
        return symbol_type (token::TK_LB, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_LB (const std::string& v)
      {
        return symbol_type (token::TK_LB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_RB (std::string v)
      {
        return symbol_type (token::TK_RB, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_RB (const std::string& v)
      {
        return symbol_type (token::TK_RB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_LKB (std::string v)
      {
        return symbol_type (token::TK_LKB, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_LKB (const std::string& v)
      {
        return symbol_type (token::TK_LKB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_RKB (std::string v)
      {
        return symbol_type (token::TK_RKB, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_RKB (const std::string& v)
      {
        return symbol_type (token::TK_RKB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_LFB (std::string v)
      {
        return symbol_type (token::TK_LFB, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_LFB (const std::string& v)
      {
        return symbol_type (token::TK_LFB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_RFB (std::string v)
      {
        return symbol_type (token::TK_RFB, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_RFB (const std::string& v)
      {
        return symbol_type (token::TK_RFB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_COMMA (std::string v)
      {
        return symbol_type (token::TK_COMMA, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_COMMA (const std::string& v)
      {
        return symbol_type (token::TK_COMMA, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_DOT (std::string v)
      {
        return symbol_type (token::TK_DOT, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_DOT (const std::string& v)
      {
        return symbol_type (token::TK_DOT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_OR (std::string v)
      {
        return symbol_type (token::TK_OR, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_OR (const std::string& v)
      {
        return symbol_type (token::TK_OR, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_AND (std::string v)
      {
        return symbol_type (token::TK_AND, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_AND (const std::string& v)
      {
        return symbol_type (token::TK_AND, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_LT (std::string v)
      {
        return symbol_type (token::TK_LT, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_LT (const std::string& v)
      {
        return symbol_type (token::TK_LT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_GR (std::string v)
      {
        return symbol_type (token::TK_GR, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_GR (const std::string& v)
      {
        return symbol_type (token::TK_GR, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_GE (std::string v)
      {
        return symbol_type (token::TK_GE, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_GE (const std::string& v)
      {
        return symbol_type (token::TK_GE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_LE (std::string v)
      {
        return symbol_type (token::TK_LE, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_LE (const std::string& v)
      {
        return symbol_type (token::TK_LE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_EQ (std::string v)
      {
        return symbol_type (token::TK_EQ, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_EQ (const std::string& v)
      {
        return symbol_type (token::TK_EQ, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_NE (std::string v)
      {
        return symbol_type (token::TK_NE, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_NE (const std::string& v)
      {
        return symbol_type (token::TK_NE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_CONCAT (std::string v)
      {
        return symbol_type (token::TK_CONCAT, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_CONCAT (const std::string& v)
      {
        return symbol_type (token::TK_CONCAT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_PLUS (std::string v)
      {
        return symbol_type (token::TK_PLUS, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_PLUS (const std::string& v)
      {
        return symbol_type (token::TK_PLUS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_MINUS (std::string v)
      {
        return symbol_type (token::TK_MINUS, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_MINUS (const std::string& v)
      {
        return symbol_type (token::TK_MINUS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_MUL (std::string v)
      {
        return symbol_type (token::TK_MUL, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_MUL (const std::string& v)
      {
        return symbol_type (token::TK_MUL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_DIV (std::string v)
      {
        return symbol_type (token::TK_DIV, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_DIV (const std::string& v)
      {
        return symbol_type (token::TK_DIV, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_PREC (std::string v)
      {
        return symbol_type (token::TK_PREC, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_PREC (const std::string& v)
      {
        return symbol_type (token::TK_PREC, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_CARET (std::string v)
      {
        return symbol_type (token::TK_CARET, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_CARET (const std::string& v)
      {
        return symbol_type (token::TK_CARET, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_NOT (std::string v)
      {
        return symbol_type (token::TK_NOT, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_NOT (const std::string& v)
      {
        return symbol_type (token::TK_NOT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TK_HASH (std::string v)
      {
        return symbol_type (token::TK_HASH, std::move (v));
      }
#else
      static
      symbol_type
      make_TK_HASH (const std::string& v)
      {
        return symbol_type (token::TK_HASH, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UMINUS ()
      {
        return symbol_type (token::UMINUS);
      }
#else
      static
      symbol_type
      make_UMINUS ()
      {
        return symbol_type (token::UMINUS);
      }
#endif


  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 521,     ///< Last index in yytable_.
      yynnts_ = 41,  ///< Number of nonterminal symbols.
      yyfinal_ = 4, ///< Termination state number.
      yyntokens_ = 56  ///< Number of tokens.
    };


  };

  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
    };
    const int user_token_number_max_ = 310;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
  {
    switch (this->type_get ())
    {
      case 90: // opcommadots
        value.move< bool > (std::move (that.value));
        break;

      case 23: // TK_NUMBER
        value.move< double > (std::move (that.value));
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
        value.move< rapidjson::Document * > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
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
        value.move< std::vector<rapidjson::Document *> > (std::move (that.value));
        break;

      case 73: // dotnames
      case 78: // namelist
      case 79: // commanames
        value.move< std::vector<std::string> > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->type_get ())
    {
      case 90: // opcommadots
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case 23: // TK_NUMBER
        value.copy< double > (YY_MOVE (that.value));
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
        value.copy< rapidjson::Document * > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
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
        value.copy< std::vector<rapidjson::Document *> > (YY_MOVE (that.value));
        break;

      case 73: // dotnames
      case 78: // namelist
      case 79: // commanames
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 90: // opcommadots
        value.move< bool > (YY_MOVE (s.value));
        break;

      case 23: // TK_NUMBER
        value.move< double > (YY_MOVE (s.value));
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
        value.move< rapidjson::Document * > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
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
        value.move< std::vector<rapidjson::Document *> > (YY_MOVE (s.value));
        break;

      case 73: // dotnames
      case 78: // namelist
      case 79: // commanames
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

} // yy
#line 2546 "y.tab.hpp"





#endif // !YY_YY_Y_TAB_HPP_INCLUDED
