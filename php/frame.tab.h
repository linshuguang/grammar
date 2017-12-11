/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1685 of yacc.c  */
#line 23 "frame.y"

  class AST *a;
  class ListAST *l;
  zval * zv;



/* Line 1685 of yacc.c  */
#line 190 "frame.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


