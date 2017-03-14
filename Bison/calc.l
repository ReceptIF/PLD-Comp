%{
#include <stdio.h>
#include <stdlib.h>
#include "calc.tab.h"
%}
%option noyywrap
name      ^([a-zA-Z]+[a-zA-Z_0-9]*)
nValue     ^([0-9]+)
cValue     ^'(.)'
comment     \/\*(.|[\r\n])*?\*\/
incl       ^(#.+>)

%%

[ \n\t]      { /* ignore */ }

{name}     { return NAME; }
{nValue}     { return NVALUE; }
{cValue}     { return CVALUE; }
{comment}     { /* ignore */ }
{incl}     { return INCL; }

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
";"          { return POINTVIR; }
"{"          { return CHEVOPEN; }
"}"          { return CHEVCLOSE; }
"("          { return POPEN; }
")"          { return PCLOSE; }
"["          { return PCLOSE; }
"]"          { return PCLOSE; }
","          { return PCLOSE; }
"putchar"    { return PUTCHAR; }
"getchar"    { return GETCHAR; }
"return"     { return RETURN; }
"break"      { return BREAK; }
%%