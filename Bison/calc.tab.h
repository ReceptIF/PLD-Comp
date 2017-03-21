/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_CALC_TAB_H_INCLUDED
# define YY_YY_CALC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    EGAL = 258,
    PLUS = 259,
    MULT = 260,
    DIV = 261,
    MOINS = 262,
    AND = 263,
    DAND = 264,
    OR = 265,
    DOR = 266,
    DEGAL = 267,
    INFEQ = 268,
    SUPEQ = 269,
    DIFF = 270,
    MOD = 271,
    XOR = 272,
    PLUSEQ = 273,
    MULTEQ = 274,
    DIVEQ = 275,
    MOINSEQ = 276,
    DPLUS = 277,
    DMOINS = 278,
    NOT = 279,
    MODEQ = 280,
    DSUP = 281,
    DINF = 282,
    INF = 283,
    SUP = 284,
    ANDEQ = 285,
    OREQ = 286,
    IF = 287,
    ELSE = 288,
    WHILE = 289,
    FOR = 290,
    CHAR = 291,
    INT32 = 292,
    INT64 = 293,
    VOID = 294,
    POINTVIR = 295,
    CHEVOPEN = 296,
    CHEVCLOSE = 297,
    POPEN = 298,
    PCLOSE = 299,
    COPEN = 300,
    CCLOSE = 301,
    VIRG = 302,
    PUTCHAR = 303,
    GETCHAR = 304,
    RETURN = 305,
    BREAK = 306,
    NAME = 307,
    NVALUE = 308,
    CVALUE = 309,
    INCL = 310,
    DPLUSAVANT = 311,
    DMOINSAVANT = 312
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 31 "calc.y" /* yacc.c:1909  */

   int ival; 
   double dval;
   char* cval;

   Bloc *block;
   Expression *expr;
   Fonction *fonct;
   Programme *prog;

#line 123 "calc.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (int * resultat, Bloc ** block, Expression ** expr, Fonction ** fonct);

#endif /* !YY_YY_CALC_TAB_H_INCLUDED  */
