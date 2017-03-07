%{
#include <stdio.h>
void yyerror(int *, const char *);
int yylex(void);
%}
%union {
   int ival; 
}

%token EGAL PLUS MULT DIV MOINS AND DAND OR DOR DEGAL INFEQ SUPEQ DIFF MOD XOR PLUSEQ MULTEQ DIVEQ MOINSEQ DPLUS DMOINS NOT MODEQ DSUP DINF INF SUP ANDEQ OREQ IF ELSE WHILE FOR CHAR INT32 INT64 VOID POINTVIR CHEVOPEN CHEVCLOSE POPEN PCLOSE COPEN CCLOSE EPSI VIRG PUTCHAR GETCHAR RETURN BREAK
%token <ival> ENTIER

%type <ival> expr

%left MOINS PLUS
%left MULT DIV

%parse-param { int * resultat }

%%

axiome : expr { *resultat = $1; }
       ;

expr : expr PLUS expr { $$ = $1 + $3; }
     | expr MULT expr  { $$ = $1 * $3; }
     | expr DIV expr  { $$ = $1 / $3; }
     | expr MOINS expr{ $$ = $1 - $3; }
     | OPEN expr CLOSE{ $$ = $2; }
     | ENTIER         { $$ = $1; }
     ;

%%

void yyerror(int * res, const char * msg) {
   printf("Syntax error : %s\n",msg);
}

int main(void) {
   int res = 0;
   yyparse(&res);
   printf("Résutlat : %d\n",res);
   return 0;
}

