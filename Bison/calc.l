%{
#include <iostream>
#include <string>

#include "../AppelFonction.h"
#include "../Bloc.h"
#include "../Break.h"
#include "../Clause.h"
#include "../Declaration.h"
#include "../Expression.h"
#include "../ExpressionBinaire.h"
#include "../ExpressionConstante.h"
#include "../ExpressionUnaire.h"
#include "../ExpressionVariable.h"
#include "../Fonction.h"
#include "../For.h"
#include "../Instruction.h"
#include "../Programme.h"
#include "../Return.h"
#include "../StructCond.h"
#include "../Structure.h"
#include "../Type.h"
#include "../Variable.h"
#include "../VariableSimple.h"
#include "../VariableTableau.h"
#include "../While.h"

/* INCLUDEs AU DESSUS DE CETTE LIGNE */
#include "calc.tab.h"
%}
%option noyywrap
name      [a-zA-Z]+[a-zA-Z_0-9]*
nValue     [0-9]+
cValue     "'"."'"
comment     \/\*(.|[\r\n])*?\*\/
incl       ^\#.*\>

%%

[ \n\t]      { /* ignore */ }

"="          { return EGAL; }
"+"          { return PLUS; }
"*"          { return MULT; }
"/"          { return DIV; }
"-"          { return MOINS; }
"&"          { return AND; }
"&&"         { return DAND; }
"|"          { return OR; }
"||"         { return DOR; }
"=="         { return DEGAL; }
"<="         { return INFEQ; }
">="         { return SUPEQ; }
"!="         { return DIFF; }
"%"          { return MOD; }
"^"          { return XOR; }
"+="         { return PLUSEQ; }
"*="         { return MULTEQ; }
"/="         { return DIVEQ; }
"-="         { return MOINSEQ; }
"++"         { return DPLUS; }
"--"         { return DMOINS; }
"!"          { return NOT; }
"%="         { return MODEQ; }
">>"         { return DSUP; }
"<<"         { return DINF; }
"<"          { return INF; }
">"          { return SUP; }
"&="         { return ANDEQ; }
"|="         { return OREQ; }
"if"         { return IF; }
"else"       { return ELSE; }
"while"      { return WHILE; }
"for"        { return FOR; }
"char"       { return CHAR; }
"int32_t"    { return INT32; }
"int64_t"    { return INT64; }
"void"       { return VOID; }
","			     { return VIRG; }
";"          { return POINTVIR; }
"{"          { return CHEVOPEN; }
"}"          { return CHEVCLOSE; }
"("          { return POPEN; }
")"          { return PCLOSE; }
"["          { return COPEN; }
"]"          { return CCLOSE; }
"return"     { return RETURN; }
"break"      { return BREAK; }

{name}       { yylval.cval = strdup(yytext); return NAME; }
{nValue}     { yylval.ival = atoi(yytext); return NVALUE; }
{cValue}     { yylval.ival = yytext[1]; return CVALUE; }
{comment}    { /* ignore */ }
{incl}       { return INCL; }
%%
