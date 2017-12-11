/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "frame.y"

#include "ast.hpp"
#include "sym.hpp"
#include "adt.hpp"
#include "mod.hpp"
#include "conf.hpp"
#include "main.hpp"
#include "array.hpp"

#include <iostream>
#include <string>
#include<cstring>

using namespace std;
extern "C"
{
	void yyerror(const char *s);
	int yylex(void);
};
class AST * top=NULL;


/* Line 189 of yacc.c  */
#line 95 "frame.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_PRINT = 258,
     T_REQUIRE_ONCE = 259,
     T_REQUIRE = 260,
     T_EVAL = 261,
     T_INCLUDE_ONCE = 262,
     T_INCLUDE = 263,
     T_LOGICAL_OR = 264,
     T_LOGICAL_XOR = 265,
     T_LOGICAL_AND = 266,
     T_SR_EQUAL = 267,
     T_SL_EQUAL = 268,
     T_XOR_EQUAL = 269,
     T_OR_EQUAL = 270,
     T_AND_EQUAL = 271,
     T_MOD_EQUAL = 272,
     T_CONCAT_EQUAL = 273,
     T_DIV_EQUAL = 274,
     T_MUL_EQUAL = 275,
     T_MINUS_EQUAL = 276,
     T_PLUS_EQUAL = 277,
     T_BOOLEAN_OR = 278,
     T_BOOLEAN_AND = 279,
     T_IS_NOT_IDENTICAL = 280,
     T_IS_IDENTICAL = 281,
     T_IS_NOT_EQUAL = 282,
     T_IS_EQUAL = 283,
     T_IS_GREATER_OR_EQUAL = 284,
     T_IS_SMALLER_OR_EQUAL = 285,
     T_SR = 286,
     T_SL = 287,
     T_INSTANCEOF = 288,
     T_UNSET_CAST = 289,
     T_BOOL_CAST = 290,
     T_OBJECT_CAST = 291,
     T_ARRAY_CAST = 292,
     T_STRING_CAST = 293,
     T_DOUBLE_CAST = 294,
     T_INT_CAST = 295,
     T_DEC = 296,
     T_INC = 297,
     T_CLONE = 298,
     T_NEW = 299,
     T_EXIT = 300,
     T_IF = 301,
     T_ELSEIF = 302,
     T_ELSE = 303,
     T_ENDIF = 304,
     T_INLINE_HTML = 305,
     T_CHARACTER = 306,
     T_BAD_CHARACTER = 307,
     T_ENCAPSED_AND_WHITESPACE = 308,
     T_ECHO = 309,
     T_DO = 310,
     T_WHILE = 311,
     T_ENDWHILE = 312,
     T_FOR = 313,
     T_ENDFOR = 314,
     T_FOREACH = 315,
     T_ENDFOREACH = 316,
     T_DECLARE = 317,
     T_ENDDECLARE = 318,
     T_AS = 319,
     T_SWITCH = 320,
     T_ENDSWITCH = 321,
     T_CASE = 322,
     T_DEFAULT = 323,
     T_BREAK = 324,
     T_CONTINUE = 325,
     T_GOTO = 326,
     T_FUNCTION = 327,
     T_CONST = 328,
     T_RETURN = 329,
     T_TRY = 330,
     T_CATCH = 331,
     T_THROW = 332,
     T_USE = 333,
     T_INSTEADOF = 334,
     T_GLOBAL = 335,
     T_PUBLIC = 336,
     T_PROTECTED = 337,
     T_PRIVATE = 338,
     T_FINAL = 339,
     T_ABSTRACT = 340,
     T_STATIC = 341,
     T_VAR = 342,
     T_UNSET = 343,
     T_ISSET = 344,
     T_EMPTY = 345,
     T_HALT_COMPILER = 346,
     T_CLASS = 347,
     T_TRAIT = 348,
     T_INTERFACE = 349,
     T_EXTENDS = 350,
     T_IMPLEMENTS = 351,
     T_OBJECT_OPERATOR = 352,
     T_DOUBLE_ARROW = 353,
     T_LIST = 354,
     T_ARRAY = 355,
     T_CALLABLE = 356,
     T_CLASS_C = 357,
     T_TRAIT_C = 358,
     T_METHOD_C = 359,
     T_FUNC_C = 360,
     T_LINE = 361,
     T_FILE = 362,
     T_COMMENT = 363,
     T_DOC_COMMENT = 364,
     T_OPEN_TAG = 365,
     T_OPEN_TAG_WITH_ECHO = 366,
     T_CLOSE_TAG = 367,
     T_WHITESPACE = 368,
     T_START_HEREDOC = 369,
     T_END_HEREDOC = 370,
     T_DOLLAR_OPEN_CURLY_BRACES = 371,
     T_CURLY_OPEN = 372,
     T_PAAMAYIM_NEKUDOTAYIM = 373,
     T_NAMESPACE = 374,
     T_NS_C = 375,
     T_DIR = 376,
     T_NS_SEPARATOR = 377,
     _EOF = 378,
     T_CONSTANT_ENCAPSED_STRING = 379,
     T_LNUMBER = 380,
     T_DNUMBER = 381,
     T_STRING = 382,
     T_STRING_VARNAME = 383,
     T_VARIABLE = 384,
     T_NUM_STRING = 385,
     UMINUS = 386
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 23 "frame.y"

  class AST *a;
  class ListAST *l;
  zval * zv;



/* Line 214 of yacc.c  */
#line 270 "frame.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 282 "frame.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1311

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  159
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNRULES -- Number of states.  */
#define YYNSTATES  304

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   386

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,   157,     2,   158,    44,    28,     2,
     150,   151,    42,    39,   147,    40,    41,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    24,   154,
      33,   155,    34,    23,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,   156,    27,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   152,   148,   153,    47,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    25,    26,
      29,    30,    31,    32,    35,    36,    37,    38,    46,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   149
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      18,    29,    32,    33,    35,    37,    39,    40,    43,    48,
      49,    51,    52,    54,    56,    59,    63,    71,    77,    85,
      95,   101,   104,   108,   111,   115,   118,   122,   126,   130,
     133,   142,   151,   153,   157,   158,   161,   163,   166,   168,
     173,   175,   180,   184,   189,   194,   200,   201,   207,   212,
     214,   216,   218,   219,   226,   227,   230,   231,   233,   237,
     239,   241,   243,   247,   250,   253,   256,   259,   263,   267,
     271,   275,   279,   283,   286,   289,   293,   297,   301,   305,
     309,   313,   317,   323,   325,   328,   330,   335,   339,   342,
     343,   354,   356,   358,   362,   363,   365,   366,   369,   375,
     379,   383,   385,   389,   391,   393,   396,   399,   401,   404,
     406,   411,   416,   421,   423,   427,   429,   431,   433,   435,
     437,   439,   440,   441,   444,   448,   450,   452,   454,   456,
     458,   463,   465,   467,   472,   473,   475,   480,   485,   487,
     488,   490,   492,   496,   500,   502
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     160,     0,    -1,   161,    -1,   161,   163,    -1,    -1,   143,
      -1,   173,    -1,   164,    -1,   165,    -1,    -1,   190,   166,
     172,   143,   150,   169,   151,   152,   167,   153,    -1,   167,
     168,    -1,    -1,   173,    -1,   164,    -1,   170,    -1,    -1,
     171,   145,    -1,   170,   147,   171,   145,    -1,    -1,   116,
      -1,    -1,    28,    -1,   174,    -1,   143,    24,    -1,   152,
     167,   153,    -1,    62,   150,   187,   151,   173,   183,   184,
      -1,    72,   150,   187,   151,   182,    -1,    71,   173,    72,
     150,   187,   151,   154,    -1,    74,   150,   185,   154,   185,
     154,   185,   151,   177,    -1,    81,   150,   187,   151,   179,
      -1,    85,   154,    -1,    85,   187,   154,    -1,    86,   154,
      -1,    86,   187,   154,    -1,    90,   154,    -1,    90,   188,
     154,    -1,    90,   206,   154,    -1,    96,   195,   154,    -1,
     187,   154,    -1,    76,   150,   206,    80,   176,   175,   151,
     178,    -1,    76,   150,   188,    80,   206,   175,   151,   178,
      -1,   154,    -1,    87,   143,   154,    -1,    -1,   114,   176,
      -1,   206,    -1,    28,   206,    -1,   173,    -1,    24,   167,
      75,   154,    -1,   173,    -1,    24,   167,    77,   154,    -1,
     152,   180,   153,    -1,   152,   154,   180,   153,    -1,    24,
     180,    82,   154,    -1,    24,   154,   180,    82,   154,    -1,
      -1,   180,    83,   187,   181,   167,    -1,   180,    84,   181,
     167,    -1,    24,    -1,   154,    -1,   173,    -1,    -1,   183,
      63,   150,   187,   151,   173,    -1,    -1,    64,   173,    -1,
      -1,   186,    -1,   186,   147,   187,    -1,   187,    -1,   216,
      -1,   188,    -1,   206,   155,   187,    -1,   205,    57,    -1,
      57,   205,    -1,   205,    56,    -1,    56,   205,    -1,   187,
      41,   187,    -1,   187,    39,   187,    -1,   187,    40,   187,
      -1,   187,    42,   187,    -1,   187,    43,   187,    -1,   187,
      44,   187,    -1,    45,   187,    -1,    47,   187,    -1,   187,
      32,   187,    -1,   187,    31,   187,    -1,   187,    33,   187,
      -1,   187,    36,   187,    -1,   187,    34,   187,    -1,   187,
      35,   187,    -1,   150,   187,   151,    -1,   187,    23,   187,
      24,   187,    -1,   199,    -1,    61,   204,    -1,   191,    -1,
     116,   150,   193,   151,    -1,    58,   193,   156,    -1,     3,
     187,    -1,    -1,   190,   172,   150,   189,   169,   151,   203,
     152,   167,   153,    -1,    88,    -1,   202,    -1,   157,   197,
     157,    -1,    -1,   147,    -1,    -1,   194,   192,    -1,   194,
     147,   187,   114,   187,    -1,   194,   147,   187,    -1,   187,
     114,   187,    -1,   187,    -1,   195,   147,   196,    -1,   196,
      -1,   145,    -1,   197,   198,    -1,   197,    69,    -1,   198,
      -1,    69,   198,    -1,   145,    -1,   145,    58,   201,   156,
      -1,   105,   150,   200,   151,    -1,   106,   150,   206,   151,
      -1,   206,    -1,   200,   147,   206,    -1,   143,    -1,   146,
      -1,   145,    -1,   141,    -1,   142,    -1,   140,    -1,    -1,
      -1,   150,   151,    -1,   150,   187,   151,    -1,   206,    -1,
     207,    -1,   208,    -1,   212,    -1,   209,    -1,   209,    58,
     211,   156,    -1,   210,    -1,   145,    -1,   158,   152,   187,
     153,    -1,    -1,   187,    -1,   162,   150,   213,   151,    -1,
     215,   150,   213,   151,    -1,   214,    -1,    -1,   188,    -1,
     206,    -1,   214,   147,   188,    -1,   214,   147,   206,    -1,
     209,    -1,   206,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   250,   250,   254,   255,   259,   263,   264,   269,   273,
     273,   289,   294,   298,   299,   303,   304,   309,   314,   322,
     323,   327,   328,   334,   335,   343,   348,   354,   358,   362,
     366,   372,   376,   380,   384,   388,   392,   396,   400,   404,
     408,   414,   418,   419,   426,   427,   432,   433,   438,   439,
     445,   446,   453,   457,   461,   465,   474,   477,   483,   492,
     493,   497,   502,   503,   512,   513,   518,   519,   523,   524,
     528,   529,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     563,   568,   576,   577,   580,   582,   586,   587,   591,   592,
     593,   594,   598,   603,   611,   618,   619,   620,   621,   625,
     626,   631,   635,   642,   646,   654,   655,   656,   660,   661,
     662,   668,   674,   675,   676,   680,   683,   688,   689,   694,
     698,   699,   704,   710,   714,   715,   719,   725,   732,   733,
     737,   741,   745,   750,   759,   763
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"print (T_PRINT)\"",
  "\"require_once (T_REQUIRE_ONCE)\"", "\"require (T_REQUIRE)\"",
  "\"eval (T_EVAL)\"", "\"include_once (T_INCLUDE_ONCE)\"",
  "\"include (T_INCLUDE)\"", "\"or (T_LOGICAL_OR)\"",
  "\"xor (T_LOGICAL_XOR)\"", "\"and (T_LOGICAL_AND)\"",
  "\">>= (T_SR_EQUAL)\"", "\"<<= (T_SL_EQUAL)\"", "\"^= (T_XOR_EQUAL)\"",
  "\"|= (T_OR_EQUAL)\"", "\"&= (T_AND_EQUAL)\"", "\"%= (T_MOD_EQUAL)\"",
  "\".= (T_CONCAT_EQUAL)\"", "\"/= (T_DIV_EQUAL)\"",
  "\"*= (T_MUL_EQUAL)\"", "\"-= (T_MINUS_EQUAL)\"",
  "\"+= (T_PLUS_EQUAL)\"", "'?'", "':'", "\"|| (T_BOOLEAN_OR)\"",
  "\"&& (T_BOOLEAN_AND)\"", "'^'", "'&'", "\"!== (T_IS_NOT_IDENTICAL)\"",
  "\"=== (T_IS_IDENTICAL)\"", "\"!= (T_IS_NOT_EQUAL)\"",
  "\"== (T_IS_EQUAL)\"", "'<'", "'>'", "\">= (T_IS_GREATER_OR_EQUAL)\"",
  "\"<= (T_IS_SMALLER_OR_EQUAL)\"", "\">> (T_SR)\"", "\"<< (T_SL)\"",
  "'+'", "'-'", "'.'", "'*'", "'/'", "'%'", "'!'",
  "\"instanceof (T_INSTANCEOF)\"", "'~'", "'@'",
  "\"(unset) (T_UNSET_CAST)\"", "\"(bool) (T_BOOL_CAST)\"",
  "\"(object) (T_OBJECT_CAST)\"", "\"(array) (T_ARRAY_CAST)\"",
  "\"(string) (T_STRING_CAST)\"", "\"(double) (T_DOUBLE_CAST)\"",
  "\"(int) (T_INT_CAST)\"", "\"-- (T_DEC)\"", "\"++ (T_INC)\"", "'['",
  "\"clone (T_CLONE)\"", "\"new (T_NEW)\"", "\"exit (T_EXIT)\"",
  "\"if (T_IF)\"", "\"elseif (T_ELSEIF)\"", "\"else (T_ELSE)\"",
  "\"endif (T_ENDIF)\"", "T_INLINE_HTML", "T_CHARACTER", "T_BAD_CHARACTER",
  "\"quoted-string and whitespace (T_ENCAPSED_AND_WHITESPACE)\"",
  "\"echo (T_ECHO)\"", "\"do (T_DO)\"", "\"while (T_WHILE)\"",
  "\"endwhile (T_ENDWHILE)\"", "\"for (T_FOR)\"", "\"endfor (T_ENDFOR)\"",
  "\"foreach (T_FOREACH)\"", "\"endforeach (T_ENDFOREACH)\"",
  "\"declare (T_DECLARE)\"", "\"enddeclare (T_ENDDECLARE)\"",
  "\"as (T_AS)\"", "\"switch (T_SWITCH)\"", "\"endswitch (T_ENDSWITCH)\"",
  "\"case (T_CASE)\"", "\"default (T_DEFAULT)\"", "\"break (T_BREAK)\"",
  "\"continue (T_CONTINUE)\"", "\"goto (T_GOTO)\"",
  "\"function (T_FUNCTION)\"", "\"const (T_CONST)\"",
  "\"return (T_RETURN)\"", "\"try (T_TRY)\"", "\"catch (T_CATCH)\"",
  "\"throw (T_THROW)\"", "\"use (T_USE)\"", "\"insteadof (T_INSTEADOF)\"",
  "\"global (T_GLOBAL)\"", "\"public (T_PUBLIC)\"",
  "\"protected (T_PROTECTED)\"", "\"private (T_PRIVATE)\"",
  "\"final (T_FINAL)\"", "\"abstract (T_ABSTRACT)\"",
  "\"static (T_STATIC)\"", "\"var (T_VAR)\"", "\"unset (T_UNSET)\"",
  "\"isset (T_ISSET)\"", "\"empty (T_EMPTY)\"",
  "\"__halt_compiler (T_HALT_COMPILER)\"", "\"class (T_CLASS)\"",
  "\"trait (T_TRAIT)\"", "\"interface (T_INTERFACE)\"",
  "\"extends (T_EXTENDS)\"", "\"implements (T_IMPLEMENTS)\"",
  "\"-> (T_OBJECT_OPERATOR)\"", "\"=> (T_DOUBLE_ARROW)\"",
  "\"list (T_LIST)\"", "\"array (T_ARRAY)\"", "\"callable (T_CALLABLE)\"",
  "\"__CLASS__ (T_CLASS_C)\"", "\"__TRAIT__ (T_TRAIT_C)\"",
  "\"__METHOD__ (T_METHOD_C)\"", "\"__FUNCTION__ (T_FUNC_C)\"",
  "\"__LINE__ (T_LINE)\"", "\"__FILE__ (T_FILE)\"",
  "\"comment (T_COMMENT)\"", "\"doc comment (T_DOC_COMMENT)\"",
  "\"open tag (T_OPEN_TAG)\"",
  "\"open tag with echo (T_OPEN_TAG_WITH_ECHO)\"",
  "\"close tag (T_CLOSE_TAG)\"", "\"whitespace (T_WHITESPACE)\"",
  "\"heredoc start (T_START_HEREDOC)\"", "\"heredoc end (T_END_HEREDOC)\"",
  "\"${ (T_DOLLAR_OPEN_CURLY_BRACES)\"", "\"{$ (T_CURLY_OPEN)\"",
  "\":: (T_PAAMAYIM_NEKUDOTAYIM)\"", "\"namespace (T_NAMESPACE)\"",
  "\"__NAMESPACE__ (T_NS_C)\"", "\"__DIR__ (T_DIR)\"",
  "\"\\\\ (T_NS_SEPARATOR)\"", "_EOF", "T_CONSTANT_ENCAPSED_STRING",
  "T_LNUMBER", "T_DNUMBER", "T_STRING", "T_STRING_VARNAME", "T_VARIABLE",
  "T_NUM_STRING", "','", "'|'", "UMINUS", "'('", "')'", "'{'", "'}'",
  "';'", "'='", "']'", "'\"'", "'$'", "$accept", "start",
  "top_statement_list", "namespace_name", "top_statement",
  "function_declaration_statement",
  "unticked_function_declaration_statement", "$@1", "inner_statement_list",
  "inner_statement", "parameter_list", "non_empty_parameter_list",
  "optional_class_type", "is_reference", "statement", "unticked_statement",
  "foreach_optional_arg", "foreach_variable", "for_statement",
  "foreach_statement", "switch_case_list", "case_list", "case_separator",
  "while_statement", "elseif_list", "else_single", "for_expr",
  "non_empty_for_expr", "expr", "expr_without_variable", "$@2", "function",
  "scalar", "possible_comma", "array_pair_list",
  "non_empty_array_pair_list", "global_var_list", "global_var",
  "encaps_list", "encaps_var", "internal_functions_in_yacc",
  "isset_variables", "encaps_var_offset", "common_scalar", "lexical_vars",
  "exit_expr", "rw_variable", "variable",
  "base_variable_with_function_calls", "base_variable",
  "reference_variable", "compound_variable", "dim_offset", "function_call",
  "function_call_parameter_list", "non_empty_function_call_parameter_list",
  "variable_without_objects", "r_variable", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    63,    58,   278,   279,    94,    38,   280,
     281,   282,   283,    60,    62,   284,   285,   286,   287,    43,
      45,    46,    42,    47,    37,    33,   288,   126,    64,   289,
     290,   291,   292,   293,   294,   295,   296,   297,    91,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,    44,   124,   386,
      40,    41,   123,   125,    59,    61,    93,    34,    36
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   159,   160,   161,   161,   162,   163,   163,   164,   166,
     165,   167,   167,   168,   168,   169,   169,   170,   170,   171,
     171,   172,   172,   173,   173,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   175,   175,   176,   176,   177,   177,
     178,   178,   179,   179,   179,   179,   180,   180,   180,   181,
     181,   182,   183,   183,   184,   184,   185,   185,   186,   186,
     187,   187,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   189,
     188,   190,   191,   191,   192,   192,   193,   193,   194,   194,
     194,   194,   195,   195,   196,   197,   197,   197,   197,   198,
     198,   199,   199,   200,   200,   201,   201,   201,   202,   202,
     202,   203,   204,   204,   204,   205,   206,   207,   207,   208,
     209,   209,   210,   210,   211,   211,   212,   212,   213,   213,
     214,   214,   214,   214,   215,   216
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     0,
      10,     2,     0,     1,     1,     1,     0,     2,     4,     0,
       1,     0,     1,     1,     2,     3,     7,     5,     7,     9,
       5,     2,     3,     2,     3,     2,     3,     3,     3,     2,
       8,     8,     1,     3,     0,     2,     1,     2,     1,     4,
       1,     4,     3,     4,     4,     5,     0,     5,     4,     1,
       1,     1,     0,     6,     0,     2,     0,     1,     3,     1,
       1,     1,     3,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     5,     1,     2,     1,     4,     3,     2,     0,
      10,     1,     1,     3,     0,     1,     0,     2,     5,     3,
       3,     1,     3,     1,     1,     2,     2,     1,     2,     1,
       4,     4,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     0,     0,     2,     3,     1,     1,     1,     1,     1,
       4,     1,     1,     4,     0,     1,     4,     4,     1,     0,
       1,     1,     3,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,   106,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,     0,     0,     0,     0,     0,   130,   128,   129,     5,
     142,     0,    12,    42,     0,     0,     0,     3,     7,     8,
       6,    23,     0,    71,     9,    95,    93,   102,     0,   155,
     136,   137,   139,   141,   138,     0,    70,     5,    98,    21,
      83,    84,    76,   135,    74,   111,     0,   104,     0,    94,
       0,     0,     0,    66,     0,     0,    31,     0,    33,     0,
       0,    35,     0,    71,   155,   114,     0,   113,     0,     0,
     106,    24,     0,     0,     0,   119,     0,   117,     0,   149,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    22,    21,     0,    75,    73,     0,
     144,   149,     0,    97,   105,   107,   133,     0,     0,     0,
       0,     0,    67,    69,    71,   155,     0,    32,    34,    43,
      36,    37,     0,    38,     0,   123,     0,     0,    91,    25,
      14,    11,    13,   118,     0,   116,   103,   115,     0,    71,
     155,     0,   148,     0,    86,    85,    87,    89,    90,    88,
      78,    79,    77,    80,    81,    82,     0,    99,    72,   145,
       0,     0,   110,   109,   134,     0,     0,     0,    66,     0,
       0,     0,     0,   112,     0,   121,   122,    96,   125,   127,
     126,     0,   143,   146,     0,     0,     0,    16,   140,   147,
       0,    62,     0,    61,    27,     0,    68,    44,     0,    44,
      46,    56,    56,    30,   124,   120,    71,   155,    92,    16,
      20,     0,    15,     0,   108,    64,     0,    66,     0,     0,
      47,     0,    56,     0,    56,     0,     0,   131,    19,    17,
       0,     0,    26,    28,     0,    45,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,    65,     0,
      12,    50,    41,    40,     0,    54,     0,    59,    60,    12,
      53,    12,    12,    18,     0,    12,    48,    29,     0,    55,
      12,    58,     0,     0,     0,     0,     0,    57,    10,   100,
      63,     0,    51,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    36,    37,   150,    39,   115,    93,   151,
     231,   232,   233,   116,   152,    41,   239,   219,   287,   272,
     223,   243,   279,   214,   235,   252,   131,   132,    42,    43,
     207,    59,    45,   125,    66,    67,    86,    87,    96,    97,
      46,   144,   201,    47,   265,    69,    48,    49,    50,    51,
      52,    53,   180,    54,   161,   162,    55,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -180
static const yytype_int16 yypact[] =
{
    -180,    11,   852,  -180,  1097,  1097,  1097,   -91,   -91,  1097,
    -108,   -97,   852,   -77,   -75,   -70,   -51,   908,   927,   -82,
    -180,   973,    18,   -30,    -1,    39,  -180,  -180,  -180,   155,
    -180,  1097,  -180,  -180,   -63,    48,    41,  -180,  -180,  -180,
    -180,  -180,   104,  -180,    -9,  -180,  -180,  -180,    31,   -33,
    -180,  -180,   -53,  -180,  -180,    61,  -180,  -180,  1249,   184,
    -180,  -180,  -180,  -180,  -180,   845,    57,    68,  1041,  -180,
    1097,   144,  1097,  1097,  1097,  1097,  -180,   134,  -180,   163,
      63,  -180,  1249,    70,     1,  -180,  -121,  -180,   -91,   -91,
    1097,  -180,   393,   240,    80,   174,   -62,  -180,  1097,  1097,
    1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,  1097,
    1097,  1097,  1097,  -180,  -180,   184,    85,  -180,  -180,  1097,
    1097,  1097,  1097,  -180,  1097,  -180,  -180,   497,   591,    86,
     666,    84,    92,  1249,   160,   -25,   751,  -180,  -180,  -180,
    -180,  -180,    18,  -180,  -117,  -180,    91,    93,  -180,  -180,
    -180,  -180,  -180,  -180,   -45,  -180,  -180,  -180,   187,   -85,
       3,    94,   101,  1225,   514,   514,   308,   308,   308,   308,
     109,   109,   109,  -180,  -180,  -180,   103,  -180,  1249,  1249,
      96,    98,  1249,  1183,  -180,   852,  1097,   852,  1097,  1097,
     -91,   -24,   -23,  -180,   -91,  -180,  -180,  -180,  -180,  -180,
    -180,    97,  -180,  -180,  1097,  1097,   100,   -89,  -180,  -180,
    1097,  -180,   765,  -180,  -180,   105,  1249,   140,   -91,   140,
    -180,   106,   108,  -180,  -180,  -180,   -66,    33,  1267,   -89,
    -180,   114,   119,   110,  1249,    29,   113,  1097,   -24,   117,
    -180,   122,  -180,    78,  -180,   -69,   125,  -180,   154,  -180,
     127,   852,  -180,  -180,   128,  -180,   315,   315,    99,   126,
    1097,   -21,   -67,  -180,   130,   132,   147,  1097,  -180,   419,
    -180,  -180,  -180,  -180,   145,  -180,     5,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  1128,  -180,  -180,  -180,   523,  -180,
    -180,   852,   598,   673,   852,   777,   146,   852,  -180,  -180,
    -180,   149,  -180,  -180
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,  -180,  -180,  -180,  -180,   302,  -180,  -180,    -7,  -180,
      76,  -180,    58,   192,     0,  -180,    89,    71,  -180,    53,
    -180,  -179,    37,  -180,  -180,  -180,  -168,  -180,     4,    -3,
    -180,    -2,  -180,  -180,   225,  -180,  -180,   177,  -180,   -26,
    -180,  -180,  -180,  -180,  -180,  -180,   164,    43,  -180,  -180,
    -180,  -180,  -180,  -180,   199,  -180,  -180,  -180
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -155
static const yytype_int16 yytable[] =
{
      44,   221,    40,   277,   218,   120,    94,   155,    58,    60,
      61,     3,    71,    65,   260,   261,   260,   261,    83,   114,
     215,    77,    79,  -135,  -135,    82,   142,   230,   100,   277,
     194,  -135,  -135,   143,   195,    92,   101,   102,   103,   104,
     105,   106,    68,   245,   107,   108,   109,   110,   111,   112,
      63,    63,    57,    70,    30,   191,   -19,  -135,  -135,  -135,
    -135,    80,  -150,   258,    84,   262,  -150,    35,   153,   254,
     157,   134,   127,    72,   128,    73,   130,   133,    82,   136,
      74,  -152,    95,    95,   263,  -152,   280,   117,   118,  -135,
    -135,    44,   250,   251,    65,   156,   159,  -154,   198,    75,
     199,   200,   158,    82,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   135,   159,    57,
      88,    30,   119,   178,   179,    82,   182,   100,   183,   222,
     119,   145,   146,   278,    35,   101,   102,   103,   104,   105,
     106,   -21,   160,   107,   108,   109,   110,   111,   112,    89,
    -151,   110,   111,   112,  -151,   141,   119,   100,   119,   278,
     259,   260,   261,    85,   160,   101,   102,   103,   104,   105,
     106,    62,    64,   107,   108,   109,   110,   111,   112,    91,
    -153,   274,   260,   261,  -153,   211,   100,   213,   119,    90,
     212,    99,   133,   216,   101,   102,   103,   104,   105,   106,
      98,   226,   107,   108,   109,   110,   111,   112,    82,   228,
     100,   121,   114,   123,   234,   124,   129,   139,   101,   102,
     103,   104,   105,   106,   140,    95,   107,   108,   109,   110,
     111,   112,   154,   217,   220,   177,   186,   224,   188,   189,
     190,   133,   196,     4,   197,   203,   206,   227,   204,   209,
     229,   268,   208,   225,   238,   249,   271,   271,   113,   237,
     242,   240,   244,   288,   276,   247,   248,   253,   256,   286,
     230,   284,   291,   257,   292,   293,   264,   267,   295,   269,
     275,   220,   281,   297,   282,     5,    44,     6,   137,    44,
      44,    44,   283,    44,   300,    44,     7,     8,     9,   289,
     302,    10,    11,   303,    38,   246,   266,   176,   241,   255,
     273,    12,    13,   290,    14,   147,    15,   138,     4,   193,
     181,    16,     0,     0,     0,    17,    18,    19,    20,     0,
      21,     0,     0,     0,     0,     0,    22,     0,     0,   270,
     202,  -155,  -155,  -155,  -155,    23,    24,   107,   108,   109,
     110,   111,   112,     0,     0,     0,    25,     0,     0,     0,
       5,     0,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,     0,    10,    11,     0,     0,
      26,    27,    28,    29,     0,    30,    12,    13,     0,    14,
      31,    15,    32,   149,    33,     0,    16,    34,    35,     0,
      17,    18,    19,    20,     0,    21,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,   100,     0,     0,     0,
      23,    24,     4,     0,   101,   102,   103,   104,   105,   106,
       0,    25,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,     0,   285,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,    28,    29,     0,
      30,     0,     0,     0,     5,    31,     6,    32,     0,    33,
       0,     0,    34,    35,     0,     7,     8,     9,     0,     0,
      10,    11,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    13,     0,    14,     0,    15,     0,     0,     0,     0,
      16,     0,     0,     0,    17,    18,    19,    20,     0,    21,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
     100,     0,     0,     0,    23,    24,     4,     0,   101,   102,
     103,   104,   105,   106,     0,    25,   107,   108,   109,   110,
     111,   112,     0,     0,   148,  -155,  -155,   103,   104,   105,
     106,     0,     0,   107,   108,   109,   110,   111,   112,    26,
      27,    28,    29,     0,    30,     0,     0,     0,     5,    31,
       6,    32,     0,    33,     0,     0,    34,    35,     0,     7,
       8,     9,     0,     0,    10,    11,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,     0,    14,     0,    15,
     296,     4,     0,     0,    16,     0,     0,     0,    17,    18,
      19,    20,     0,    21,   100,     0,     0,     0,     0,    22,
       0,     0,   101,   102,   103,   104,   105,   106,    23,    24,
     107,   108,   109,   110,   111,   112,     0,     0,     0,    25,
       0,     0,     0,     5,     0,     6,     0,     0,   184,     0,
       0,     0,     0,     0,     7,     8,     9,     0,     0,    10,
      11,     0,     0,    26,    27,    28,    29,     0,    30,    12,
      13,     0,    14,    31,    15,    32,     4,    33,     0,    16,
      34,    35,     0,    17,    18,    19,    20,     0,    21,   100,
       0,     0,     0,     0,    22,     0,     0,   101,   102,   103,
     104,   105,   106,    23,    24,   107,   108,   109,   110,   111,
     112,     0,     0,     0,    25,     0,     0,     0,     5,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,    10,    11,     0,     0,    26,    27,
      28,    29,   185,    30,    12,    13,     0,    14,    31,    15,
      32,   298,    33,     0,    16,    34,    35,     0,    17,    18,
      19,    20,     0,    21,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,   100,     0,     0,     0,    23,    24,
       4,     0,   101,   102,   103,   104,   105,   106,   100,    25,
     107,   108,   109,   110,   111,   112,   101,   102,   103,   104,
     105,   106,     0,     0,   107,   108,   109,   110,   111,   112,
       0,     0,     0,    26,    27,    28,    29,   187,    30,     0,
       0,     0,     5,    31,     6,    32,   299,    33,     0,     0,
      34,    35,     0,     7,     8,     9,     0,     0,    10,    11,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    13,
       0,    14,   301,    15,     0,     4,     0,     0,    16,     0,
       0,     0,    17,    18,    19,    20,     0,    21,   100,     0,
       0,     0,     0,    22,     0,     0,   101,   102,   103,   104,
     105,   106,    23,    24,   107,   108,   109,   110,   111,   112,
       0,     0,     0,    25,     0,     0,     0,     5,     0,     6,
       0,     0,   192,     0,     0,     0,     0,     0,     7,     8,
       9,     4,     0,    10,    11,     0,   236,    26,    27,    28,
      29,     0,    30,    12,    13,     0,    14,    31,    15,    32,
       4,    33,     0,    16,    34,    35,     0,    17,    18,    19,
      20,     0,    21,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     5,     0,     6,     0,    23,    24,   122,
       0,     0,     0,     0,     7,     8,     9,     0,    25,    10,
       0,     0,     5,     0,     6,     0,     4,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,    10,     0,
       0,     0,    26,    27,    28,    29,    20,    30,     0,     0,
       0,     0,    31,     0,    32,     0,    33,     0,     0,    34,
      35,     0,     0,    23,    24,    20,     0,     0,     5,     0,
       6,     0,     0,     0,    25,     0,     0,     0,     0,     7,
       8,     9,    23,    24,    10,     0,     0,     0,     0,     0,
       0,     0,     0,    25,     4,     0,     0,     0,    26,    27,
      28,    57,     0,    30,     0,     0,     0,     0,    31,     0,
       0,    20,    76,     0,     0,    34,    35,    26,    27,    28,
      57,     0,    30,     0,     0,     0,     0,    31,    23,    24,
       0,    78,     0,     0,    34,    35,     5,     0,     6,    25,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       4,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    27,    28,    57,     0,    30,     0,
       0,     0,     0,    31,     0,     0,     0,    81,     0,    20,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     6,     0,    23,    24,     0,     0,
       0,   100,     0,     7,     8,     9,     0,    25,    10,   101,
     102,   103,   104,   105,   106,     0,     0,   107,   108,   109,
     110,   111,   112,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    27,    28,    57,    20,    30,     0,     0,     0,
       0,    31,   126,     0,     0,     0,     0,     0,    34,    35,
       0,     0,    23,    24,     0,     0,   100,     0,     0,     0,
       0,     0,     0,    25,   101,   102,   103,   104,   105,   106,
       0,     0,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,    27,    28,
      57,     0,    30,     0,     0,     0,     0,    31,   100,   205,
       0,     0,     0,     0,    34,    35,   101,   102,   103,   104,
     105,   106,     0,     0,   107,   108,   109,   110,   111,   112,
       0,     0,   100,     0,     0,     0,     0,     0,     0,   294,
     101,   102,   103,   104,   105,   106,     0,     0,   107,   108,
     109,   110,   111,   112,     0,     0,     0,   210,   101,   102,
     103,   104,   105,   106,     0,     0,   107,   108,   109,   110,
     111,   112
};

static const yytype_int16 yycheck[] =
{
       2,    24,     2,    24,    28,    58,    69,    69,     4,     5,
       6,     0,    12,     9,    83,    84,    83,    84,    21,    28,
     188,    17,    18,    56,    57,    21,   147,   116,    23,    24,
     147,    56,    57,   154,   151,    31,    31,    32,    33,    34,
      35,    36,   150,   222,    39,    40,    41,    42,    43,    44,
       7,     8,   143,   150,   145,    80,   145,    56,    57,    56,
      57,   143,   147,   242,    21,   244,   151,   158,    94,   237,
      96,    74,    68,   150,    70,   150,    72,    73,    74,    75,
     150,   147,   145,   145,   153,   151,   153,    56,    57,    56,
      57,    93,    63,    64,    90,   157,    99,   150,   143,   150,
     145,   146,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    74,   121,   143,
     150,   145,   155,   119,   120,   121,   122,    23,   124,   152,
     155,    88,    89,   154,   158,    31,    32,    33,    34,    35,
      36,   150,    99,    39,    40,    41,    42,    43,    44,   150,
     147,    42,    43,    44,   151,   154,   155,    23,   155,   154,
      82,    83,    84,   145,   121,    31,    32,    33,    34,    35,
      36,     7,     8,    39,    40,    41,    42,    43,    44,    24,
     147,    82,    83,    84,   151,   185,    23,   187,   155,   150,
     186,   150,   188,   189,    31,    32,    33,    34,    35,    36,
     152,   204,    39,    40,    41,    42,    43,    44,   204,   205,
      23,   150,    28,   156,   210,   147,    72,   154,    31,    32,
      33,    34,    35,    36,   154,   145,    39,    40,    41,    42,
      43,    44,    58,   190,   191,   150,   150,   194,   154,   147,
      80,   237,   151,     3,   151,   151,   143,   204,   147,   151,
     150,   251,   156,   156,   114,   145,   256,   257,   154,   154,
     154,   218,   154,   270,   260,   151,   147,   154,   151,   269,
     116,   267,   279,   151,   281,   282,   151,   150,   285,   151,
     154,   238,   152,   290,   152,    45,   288,    47,   154,   291,
     292,   293,   145,   295,   294,   297,    56,    57,    58,   154,
     154,    61,    62,   154,     2,   229,   248,   115,   219,   238,
     257,    71,    72,   276,    74,    90,    76,   154,     3,   142,
     121,    81,    -1,    -1,    -1,    85,    86,    87,    88,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    24,
     153,    33,    34,    35,    36,   105,   106,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,   116,    -1,    -1,    -1,
      45,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    61,    62,    -1,    -1,
     140,   141,   142,   143,    -1,   145,    71,    72,    -1,    74,
     150,    76,   152,   153,   154,    -1,    81,   157,   158,    -1,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
     105,   106,     3,    -1,    31,    32,    33,    34,    35,    36,
      -1,   116,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   141,   142,   143,    -1,
     145,    -1,    -1,    -1,    45,   150,    47,   152,    -1,   154,
      -1,    -1,   157,   158,    -1,    56,    57,    58,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,   105,   106,     3,    -1,    31,    32,
      33,    34,    35,    36,    -1,   116,    39,    40,    41,    42,
      43,    44,    -1,    -1,   151,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    40,    41,    42,    43,    44,   140,
     141,   142,   143,    -1,   145,    -1,    -1,    -1,    45,   150,
      47,   152,    -1,   154,    -1,    -1,   157,   158,    -1,    56,
      57,    58,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    -1,    74,    -1,    76,
      77,     3,    -1,    -1,    81,    -1,    -1,    -1,    85,    86,
      87,    88,    -1,    90,    23,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    31,    32,    33,    34,    35,    36,   105,   106,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,   116,
      -1,    -1,    -1,    45,    -1,    47,    -1,    -1,   151,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,
      62,    -1,    -1,   140,   141,   142,   143,    -1,   145,    71,
      72,    -1,    74,   150,    76,   152,     3,   154,    -1,    81,
     157,   158,    -1,    85,    86,    87,    88,    -1,    90,    23,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    31,    32,    33,
      34,    35,    36,   105,   106,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,   116,    -1,    -1,    -1,    45,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    61,    62,    -1,    -1,   140,   141,
     142,   143,   151,   145,    71,    72,    -1,    74,   150,    76,
     152,   153,   154,    -1,    81,   157,   158,    -1,    85,    86,
      87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,   105,   106,
       3,    -1,    31,    32,    33,    34,    35,    36,    23,   116,
      39,    40,    41,    42,    43,    44,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,   140,   141,   142,   143,   151,   145,    -1,
      -1,    -1,    45,   150,    47,   152,   153,   154,    -1,    -1,
     157,   158,    -1,    56,    57,    58,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      -1,    74,    75,    76,    -1,     3,    -1,    -1,    81,    -1,
      -1,    -1,    85,    86,    87,    88,    -1,    90,    23,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    31,    32,    33,    34,
      35,    36,   105,   106,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    45,    -1,    47,
      -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,     3,    -1,    61,    62,    -1,   151,   140,   141,   142,
     143,    -1,   145,    71,    72,    -1,    74,   150,    76,   152,
       3,   154,    -1,    81,   157,   158,    -1,    85,    86,    87,
      88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    45,    -1,    47,    -1,   105,   106,   114,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,   116,    61,
      -1,    -1,    45,    -1,    47,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,    -1,
      -1,    -1,   140,   141,   142,   143,    88,   145,    -1,    -1,
      -1,    -1,   150,    -1,   152,    -1,   154,    -1,    -1,   157,
     158,    -1,    -1,   105,   106,    88,    -1,    -1,    45,    -1,
      47,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    56,
      57,    58,   105,   106,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,     3,    -1,    -1,    -1,   140,   141,
     142,   143,    -1,   145,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    88,   154,    -1,    -1,   157,   158,   140,   141,   142,
     143,    -1,   145,    -1,    -1,    -1,    -1,   150,   105,   106,
      -1,   154,    -1,    -1,   157,   158,    45,    -1,    47,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
       3,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   140,   141,   142,   143,    -1,   145,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,   154,    -1,    88,
     157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    47,    -1,   105,   106,    -1,    -1,
      -1,    23,    -1,    56,    57,    58,    -1,   116,    61,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   140,   141,   142,   143,    88,   145,    -1,    -1,    -1,
      -1,   150,   151,    -1,    -1,    -1,    -1,    -1,   157,   158,
      -1,    -1,   105,   106,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,
     143,    -1,   145,    -1,    -1,    -1,    -1,   150,    23,    24,
      -1,    -1,    -1,    -1,   157,   158,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    40,    41,    42,    43,    44,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,   151,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,   114,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    40,    41,    42,
      43,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   160,   161,     0,     3,    45,    47,    56,    57,    58,
      61,    62,    71,    72,    74,    76,    81,    85,    86,    87,
      88,    90,    96,   105,   106,   116,   140,   141,   142,   143,
     145,   150,   152,   154,   157,   158,   162,   163,   164,   165,
     173,   174,   187,   188,   190,   191,   199,   202,   205,   206,
     207,   208,   209,   210,   212,   215,   216,   143,   187,   190,
     187,   187,   205,   206,   205,   187,   193,   194,   150,   204,
     150,   173,   150,   150,   150,   150,   154,   187,   154,   187,
     143,   154,   187,   188,   206,   145,   195,   196,   150,   150,
     150,    24,   187,   167,    69,   145,   197,   198,   152,   150,
      23,    31,    32,    33,    34,    35,    36,    39,    40,    41,
      42,    43,    44,   154,    28,   166,   172,    56,    57,   155,
      58,   150,   114,   156,   147,   192,   151,   187,   187,    72,
     187,   185,   186,   187,   188,   206,   187,   154,   154,   154,
     154,   154,   147,   154,   200,   206,   206,   193,   151,   153,
     164,   168,   173,   198,    58,    69,   157,   198,   187,   188,
     206,   213,   214,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   172,   150,   187,   187,
     211,   213,   187,   187,   151,   151,   150,   151,   154,   147,
      80,    80,   151,   196,   147,   151,   151,   151,   143,   145,
     146,   201,   153,   151,   147,    24,   143,   189,   156,   151,
     114,   173,   187,   173,   182,   185,   187,   206,    28,   176,
     206,    24,   152,   179,   206,   156,   188,   206,   187,   150,
     116,   169,   170,   171,   187,   183,   151,   154,   114,   175,
     206,   175,   154,   180,   154,   180,   169,   151,   147,   145,
      63,    64,   184,   154,   185,   176,   151,   151,   180,    82,
      83,    84,   180,   153,   151,   203,   171,   150,   173,   151,
      24,   173,   178,   178,    82,   154,   187,    24,   154,   181,
     153,   152,   152,   145,   187,    24,   173,   177,   167,   154,
     181,   167,   167,   167,   151,   167,    77,   167,   153,   153,
     173,    75,   154,   154
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 250 "frame.y"
    {top =  new TopStmt((yyvsp[(1) - (1)].l)); ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 254 "frame.y"
    {(yyval.l) = (yyvsp[(1) - (2)].l); (yyvsp[(1) - (2)].l)->push_back(new TopStmtListAST((yyvsp[(2) - (2)].a),NULL));;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 255 "frame.y"
    {(yyval.l)=new TopStmtListAST(NULL,NULL);;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 259 "frame.y"
    { (yyval.a) = new StrAST((yyvsp[(1) - (1)].zv)->value.str.val) ; ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 263 "frame.y"
    {  (yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 264 "frame.y"
    {  (yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 269 "frame.y"
    { (yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 273 "frame.y"
    {SYMBOL_TABLE_STACK->Push(NEW_SYMBOL_TABLE());;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 274 "frame.y"
    {
			//cout<<"function def ok"<<endl;
			
			SymbolTable * symtbl = SYMBOL_TABLE_STACK->Pop();
			if(!GLOBAL_FUNCTION_TABLE->Register((yyvsp[(4) - (10)].zv)->value.str.val)){
				cout<<"function register error"<<endl;
			}
			Symbol * symbol = GLOBAL_FUNCTION_TABLE->Lookup((yyvsp[(4) - (10)].zv)->value.str.val);
			symbol->ReVal(new Function(symtbl,(yyvsp[(6) - (10)].l),new InnerStmt((yyvsp[(9) - (10)].l))));
			
			(yyval.a) = new FunctionDeclarationStmt(NULL);
		;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 290 "frame.y"
    { 
			(yyvsp[(1) - (2)].l)->push_back( new InnerStmtListAST((yyvsp[(2) - (2)].a),NULL));
			(yyval.l)= (yyvsp[(1) - (2)].l);
		;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 294 "frame.y"
    {(yyval.l)=new InnerStmtListAST(NULL,NULL);;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 298 "frame.y"
    {(yyval.a)=(yyvsp[(1) - (1)].a); ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 299 "frame.y"
    {(yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 303 "frame.y"
    {(yyval.l)=(yyvsp[(1) - (1)].l);;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 304 "frame.y"
    {(yyval.l) = NULL;;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 310 "frame.y"
    {
			(CURRENT_SYMBOL_TABLE)->Register((yyvsp[(2) - (2)].zv)->value.str.val); 
			(yyval.l) = new ListAST(new StrAST((yyvsp[(2) - (2)].zv)->value.str.val),NULL);
		;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 315 "frame.y"
    { 
			(CURRENT_SYMBOL_TABLE)->Register((yyvsp[(4) - (4)].zv)->value.str.val); 
			(yyvsp[(1) - (4)].l)->push_back(new ListAST(new StrAST((yyvsp[(4) - (4)].zv)->value.str.val),NULL));			
		;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 322 "frame.y"
    { ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 323 "frame.y"
    {;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 327 "frame.y"
    { ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 328 "frame.y"
    { ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 334 "frame.y"
    {(yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 336 "frame.y"
    { 
				//zend_do_label(&$1 TSRMLS_CC); 
				(yyval.a) = new LabelStmt(new StrAST((yyvsp[(1) - (2)].zv)->value.str.val));
			;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 344 "frame.y"
    {
			//cout<<"unticked begin"<<endl;
			(yyval.a)=new InnerStmt((yyvsp[(2) - (3)].l));
		;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 349 "frame.y"
    { 
			ListAST * l = new ListAST(new IfFlow((yyvsp[(3) - (7)].a),(yyvsp[(5) - (7)].a)),(yyvsp[(6) - (7)].l));
			l->push_back(new ListAST((yyvsp[(7) - (7)].a),NULL));
			(yyval.a) = new IfStmt(l);
		;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 355 "frame.y"
    { 
			(yyval.a) = new WhileStmt((yyvsp[(3) - (5)].a),(yyvsp[(5) - (5)].a));
		;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 359 "frame.y"
    { 
			(yyval.a) = new DoWhileStmt((yyvsp[(2) - (7)].a),(yyvsp[(5) - (7)].a));			
		;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 363 "frame.y"
    { 
			(yyval.a) = new ForStmt((yyvsp[(3) - (9)].a),(yyvsp[(5) - (9)].a),(yyvsp[(7) - (9)].a),(yyvsp[(9) - (9)].a));
		;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 367 "frame.y"
    { 
			//cout<<"switch begin"<<endl;
			(yyval.a) = new SwitchStmt((yyvsp[(3) - (5)].a),(yyvsp[(5) - (5)].l));
			//cout<<"switch end"<<endl;
		;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 373 "frame.y"
    { 
			(yyval.a) = new BreakStmt(NULL);
		;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 377 "frame.y"
    { 
			(yyval.a) = new BreakStmt((yyvsp[(2) - (3)].a));
		;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 381 "frame.y"
    { 
			(yyval.a) = new ContinueStmt(NULL);
		;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 385 "frame.y"
    { 
			(yyval.a) = new ContinueStmt((yyvsp[(2) - (3)].a));
		;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 389 "frame.y"
    { 
			(yyval.a) = new ReturnStmt(NULL);
		;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 393 "frame.y"
    { 
			(yyval.a) = new ReturnStmt((yyvsp[(2) - (3)].a));
		;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 397 "frame.y"
    {  
			(yyval.a) = new ReturnStmt((yyvsp[(2) - (3)].a));
		;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 401 "frame.y"
    {
			(yyval.a) = new GlobalStmt((yyvsp[(2) - (3)].l));
		;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 405 "frame.y"
    { 
			(yyval.a)=new ExprStmt((yyvsp[(1) - (2)].a));
		;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 409 "frame.y"
    { 
			//new DoubleArrowExpr($5,$6);
			//zend_do_foreach_end(&$1, &$4 TSRMLS_CC); 
			(yyval.a) = new ForeachStmt((yyvsp[(3) - (8)].a),(yyvsp[(5) - (8)].a),(yyvsp[(6) - (8)].a),(yyvsp[(8) - (8)].a));
		;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 415 "frame.y"
    { 
			(yyval.a) = new ForeachStmt((yyvsp[(3) - (8)].a),(yyvsp[(5) - (8)].a),(yyvsp[(6) - (8)].a),(yyvsp[(8) - (8)].a));
		;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 418 "frame.y"
    {(yyval.a)=NULL;;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 420 "frame.y"
    { 			
			(yyval.a) = new GotoStmt(new StrAST((yyvsp[(2) - (3)].zv)->value.str.val));
		;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 426 "frame.y"
    { (yyval.a)= NULL; ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 427 "frame.y"
    { (yyval.a) = (yyvsp[(2) - (2)].a); ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 432 "frame.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 433 "frame.y"
    { ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 438 "frame.y"
    {(yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 440 "frame.y"
    {
			(yyval.a)= new InnerStmt((yyvsp[(2) - (4)].l));
		;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 445 "frame.y"
    {(yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 447 "frame.y"
    {
			(yyval.a)= new InnerStmt((yyvsp[(2) - (4)].l));
		;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 454 "frame.y"
    { 
			(yyval.l) = (yyvsp[(2) - (3)].l); 
		;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 458 "frame.y"
    { 
			(yyval.l) = (yyvsp[(3) - (4)].l); 
		;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 462 "frame.y"
    { 
			(yyval.l) = (yyvsp[(2) - (4)].l); 
		;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 466 "frame.y"
    { 
			(yyval.l) = (yyvsp[(3) - (5)].l); 
		;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 474 "frame.y"
    {
			(yyval.l) = new ListAST(NULL,NULL);
		;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 478 "frame.y"
    { 
			(yyvsp[(1) - (5)].l)->push_back(new ListAST(new CaseFlow((yyvsp[(3) - (5)].a),new InnerStmt((yyvsp[(5) - (5)].l))),NULL));
			(yyval.l) = (yyvsp[(1) - (5)].l);
			//,NULL)));
		;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 484 "frame.y"
    { 			
			(yyvsp[(1) - (4)].l)->push_back(new ListAST(new DefaultFlow(new InnerStmt((yyvsp[(4) - (4)].l))),NULL));
			(yyval.l) = (yyvsp[(1) - (4)].l);
		;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 497 "frame.y"
    {(yyval.a) =(yyvsp[(1) - (1)].a);;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 502 "frame.y"
    { (yyval.l)=new ListAST(NULL,NULL); ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 504 "frame.y"
    { 			
			(yyvsp[(1) - (6)].l)->push_back( new ListAST(new IfFlow((yyvsp[(4) - (6)].a),(yyvsp[(6) - (6)].a)),NULL));
			(yyval.l)= (yyvsp[(1) - (6)].l);
		;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 512 "frame.y"
    { (yyval.a)=NULL; ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 513 "frame.y"
    {(yyval.a)=new ElseFlow((yyvsp[(2) - (2)].a));;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 518 "frame.y"
    { (yyval.a)=NULL; ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 519 "frame.y"
    { (yyval.a) = new CommaExpr((yyvsp[(1) - (1)].l));;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 523 "frame.y"
    { (yyval.l) = (yyvsp[(1) - (3)].l); (yyvsp[(1) - (3)].l)->push_back(new ListAST((yyvsp[(3) - (3)].a),NULL)); ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 524 "frame.y"
    { (yyval.l) = new ListAST((yyvsp[(1) - (1)].a),NULL); ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 528 "frame.y"
    {(yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 529 "frame.y"
    { (yyval.a)=(yyvsp[(1) - (1)].a) ;;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 536 "frame.y"
    {  (yyval.a)=new AssignExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a)); ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 537 "frame.y"
    { (yyval.a)= new PostIncExpr((yyvsp[(1) - (2)].a)); ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 538 "frame.y"
    { (yyval.a)= new PreIncExpr((yyvsp[(2) - (2)].a));;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 539 "frame.y"
    {(yyval.a)= new PostDecExpr((yyvsp[(1) - (2)].a)); ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 540 "frame.y"
    {(yyval.a)= new PreDecExpr((yyvsp[(2) - (2)].a)); ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 541 "frame.y"
    { (yyval.a)= new ConcatExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));  ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 542 "frame.y"
    { (yyval.a)= new AddExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 543 "frame.y"
    {  (yyval.a) = new SubExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));/*$$ = newast('-', $1,$3); */;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 544 "frame.y"
    { (yyval.a) = new MulExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));/* $$ = newast('*', $1,$3); */;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 545 "frame.y"
    { (yyval.a) = new DivExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a)); /*$$ = newast('/', $1,$3); */;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 546 "frame.y"
    { (yyval.a) = new ModExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a)); /* $$ = newast('%', $1,$3);*/ ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 547 "frame.y"
    { (yyval.a) = new NotExpr((yyvsp[(2) - (2)].a)); ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 548 "frame.y"
    { (yyval.a) = new NotExpr((yyvsp[(2) - (2)].a)); ;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 549 "frame.y"
    { (yyval.a) = new EqualExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 550 "frame.y"
    { (yyval.a) = new NotEqualExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 551 "frame.y"
    { (yyval.a) = new SmallThanExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 552 "frame.y"
    { (yyval.a) = new SmallEqualExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 553 "frame.y"
    { (yyval.a) = new GreatThanExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 554 "frame.y"
    { (yyval.a) = new GreatEqualExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 555 "frame.y"
    { (yyval.a)=(yyvsp[(2) - (3)].a); ;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 556 "frame.y"
    {(yyval.a) = new QmExpr((yyvsp[(1) - (5)].a),(yyvsp[(3) - (5)].a),(yyvsp[(5) - (5)].a));;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 557 "frame.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a); ;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 558 "frame.y"
    { ;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 559 "frame.y"
    {(yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 560 "frame.y"
    {(yyval.a)=new ArrayAST((yyvsp[(3) - (4)].a));;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 561 "frame.y"
    { /*$$ = $2; */;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 562 "frame.y"
    {(yyval.a)= new Print((yyvsp[(2) - (2)].a));;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 563 "frame.y"
    {;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 564 "frame.y"
    { /*cout<<"ref"<<endl;*/;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 569 "frame.y"
    { 
	;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 576 "frame.y"
    { (yyval.a) = (yyvsp[(1) - (1)].a);;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 577 "frame.y"
    {  /*$$ = $2; */;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 586 "frame.y"
    {(yyval.a)=NULL; ;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 587 "frame.y"
    { (yyval.a) = (yyvsp[(1) - (2)].l); ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 591 "frame.y"
    {(yyvsp[(1) - (5)].l)->push_back( new ListAST(new DoubleArrowExpr((yyvsp[(3) - (5)].a),(yyvsp[(5) - (5)].a)),NULL));(yyval.l)= (yyvsp[(1) - (5)].l); ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 592 "frame.y"
    {(yyvsp[(1) - (3)].l)->push_back(new ListAST(new DoubleArrowExpr(NULL,(yyvsp[(3) - (3)].a)),NULL));(yyval.l)= (yyvsp[(1) - (3)].l); ;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 593 "frame.y"
    { (yyval.l) = new ListAST(new DoubleArrowExpr((yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a)),NULL); ;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 594 "frame.y"
    { (yyval.l) =new ListAST(new DoubleArrowExpr(NULL,(yyvsp[(1) - (1)].a)),NULL); ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 599 "frame.y"
    { 
			(yyval.l) = (yyvsp[(1) - (3)].l);
			(yyvsp[(1) - (3)].l)->push_back(new ListAST((yyvsp[(3) - (3)].a),NULL));
		;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 604 "frame.y"
    { 
			(yyval.l) = new ListAST((yyvsp[(1) - (1)].a),NULL);
		;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 612 "frame.y"
    { 
			CURRENT_SYMBOL_TABLE->RegisterGlobalRef((yyvsp[(1) - (1)].zv)->value.str.val);
			(yyval.a) = new GlobalVariableAST((yyvsp[(1) - (1)].zv)->value.str.val); 
		;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 618 "frame.y"
    {  ;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 619 "frame.y"
    { ;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 620 "frame.y"
    { ;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 621 "frame.y"
    { ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 625 "frame.y"
    { /*$$ = newref(lookup($1->value.str.val));*/ cout<<"variable"<<endl;;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 626 "frame.y"
    { ;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 632 "frame.y"
    { 
			(yyval.a) = new IsSetExpr((yyvsp[(3) - (4)].l)); 
		;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 636 "frame.y"
    { 
			(yyval.a) = new EmptyExpr((yyvsp[(3) - (4)].a));
		;}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 643 "frame.y"
    { 
			(yyval.l) = new ListAST((yyvsp[(1) - (1)].a),NULL);
		;}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 647 "frame.y"
    { 
			//$$ = $1->push_back(new ListAST($3,NULL));
		;}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 654 "frame.y"
    {  ;}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 655 "frame.y"
    {  ;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 656 "frame.y"
    { ;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 660 "frame.y"
    { (yyval.a) = new LongAST((yyvsp[(1) - (1)].zv)->value.lval); ;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 661 "frame.y"
    { (yyval.a) = new DoubleAST((yyvsp[(1) - (1)].zv)->value.dval);;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 662 "frame.y"
    {(yyval.a) = new StrAST((yyvsp[(1) - (1)].zv)->value.str.val);;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 674 "frame.y"
    { ;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 675 "frame.y"
    { ;}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 676 "frame.y"
    {;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 680 "frame.y"
    { (yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 683 "frame.y"
    { (yyval.a)=(yyvsp[(1) - (1)].a); ;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 688 "frame.y"
    {  (yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 689 "frame.y"
    {(yyval.a)=new TempVariableAST((yyvsp[(1) - (1)].a));;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 694 "frame.y"
    { (yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 698 "frame.y"
    { (yyval.a) = new FetchArrayDimVariableAST((yyvsp[(1) - (4)].a),(yyvsp[(3) - (4)].a)); ;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 699 "frame.y"
    { (yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 705 "frame.y"
    {
			//Symbol * s = 
			(CURRENT_SYMBOL_TABLE)->Register((yyvsp[(1) - (1)].zv)->value.str.val); 
			(yyval.a) = new SimpleVariableAST((yyvsp[(1) - (1)].zv)->value.str.val);
		;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 710 "frame.y"
    {   ;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 714 "frame.y"
    {(yyval.a)=NULL;   ;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 715 "frame.y"
    { (yyval.a)=(yyvsp[(1) - (1)].a); ;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 720 "frame.y"
    {  
		//cout<<"function call "<<endl;
		//$$ = NULL;
		(yyval.a) = new CallFunction((yyvsp[(1) - (4)].a), (yyvsp[(3) - (4)].l));
	;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 726 "frame.y"
    {  
		(yyval.a) = new CallFunction((yyvsp[(1) - (4)].a), (yyvsp[(3) - (4)].l));
	;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 732 "frame.y"
    { (yyval.l)=(yyvsp[(1) - (1)].l); ;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 733 "frame.y"
    {(yyval.l)=NULL;;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 738 "frame.y"
    {
			(yyval.l) = new ListAST((yyvsp[(1) - (1)].a),NULL);
		;}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 742 "frame.y"
    {
			(yyval.l) = new ListAST((yyvsp[(1) - (1)].a),NULL);
		;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 746 "frame.y"
    { 
			(yyval.l) = (yyvsp[(1) - (3)].l);
			(yyvsp[(1) - (3)].l)->push_back(new ListAST((yyvsp[(3) - (3)].a),NULL));
		;}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 751 "frame.y"
    { 
			(yyval.l) = (yyvsp[(1) - (3)].l);
			(yyvsp[(1) - (3)].l)->push_back(new ListAST((yyvsp[(3) - (3)].a),NULL));
		;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 759 "frame.y"
    {/* $$=$1; */;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 763 "frame.y"
    { (yyval.a)=(yyvsp[(1) - (1)].a);;}
    break;



/* Line 1464 of yacc.c  */
#line 3213 "frame.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 765 "frame.y"


void yyerror(const char *s)
{
	
}

int main(int argc, char *argv[])
{
	
	if(argc<2){
		cout<<"no conf"<<endl;
		return -1;
	}
	
	Conf * conf = Conf::Instance();
	Mod * mod = Mod::Instance();
	conf->LoadConf(argv[1]);
	conf->RegisterMod(mod);
	mod->Register(MOD_FUNCTION_TABLE);
	//MOD_FUNCTION_TABLE->Print();
	
	
	top=NULL;	
	yyparse();
	TopStmt * top_stmt = dynamic_cast<TopStmt*>(top);
	//cout<<"begin to parse"<<endl;
	if(top_stmt!=NULL){
		ADT * result = top_stmt->eval();
		FlowControlADT * flow_control = dynamic_cast<FlowControlADT*>(result);
		if(flow_control!=NULL && flow_control->IsGoto()){
			ADT * label = flow_control->Param();
			if(top_stmt->FindLabel(label)){
				//cout<<"found label:";label->Print();cout<<endl;
				top_stmt->Jmp(flow_control->Param());
			}else{
				cout<<"no found label:";label->Print();cout<<endl;
			}			
		}		
	}

	return 0;
}

