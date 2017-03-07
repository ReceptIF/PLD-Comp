%{
#include <stdio.h>
#include <stdlib.h>
#include "calc.tab.h"
%}
%option noyywrap
name :     ^([a-zA-Z]+[a-zA-Z_0-9]*)
nValue :    ^(\d+)/g    OU /^([0-9]+)
cValue :    ^'(.{1})’/g
comment :    \/\*(.|[\r\n])*?\*\/
incl :        ^(#.+>)
%%
[ \n\t]      { /* ignore */ }
{entier}     { yylval.ival = atoi(yytext); return ENTIER; }
"+"          { return PLUS; }
"-"          { return MOINS; }
"/"          { return DIV; }
"*"          { return MULT; }
"("          { return OPEN; }
")"          { return CLOSE; }