%{
#include <stdio.h>
void yyerror(int *, const char *);
int yylexpression(void);
%}
%union {
   int ival; 
}

%token EGAL PLUS MULT DIV MOINS AND DAND OR DOR DEGAL INFEQ SUPEQ DIFF MOD XOR PLUSEQ MULTEQ DIVEQ MOINSEQ DPLUS DMOINS NOT MODEQ DSUP DINF INF SUP ANDEQ OREQ IF ELSE WHILE FOR CHAR INT32 INT64 VOID POINTVIR CHEVOPEN CHEVCLOSE POPEN PCLOSE COPEN CCLOSE VIRG PUTCHAR GETCHAR RETURN BREAK

%token <ival> NAME
%token <ival> NVALUE
%token <ival> CVALUE
%token <ival> INCL

%type <ival> programme
%type <ival> fonction
%type <ival> affectation
%type <ival> appfct
%type <ival> bloc
%type <ival> decdef
%type <ival> el
%type <ival> eli
%type <ival> expression
%type <ival> instruction
%type <ival> le
%type <ival> lee
%type <ival> pa
%type <ival> structure
%type <ival> type
%type <ival> tpa

%left MOINS PLUS
%left MULT DIV

%parse-param { int * resultat }

%%

/*axiome : expression { *resultat = $1; }
     ;*/ 

programme : programme INCL {}
	 | programme fonction {}
	 | /* epsilon */ {}
	 ;

type : CHAR {}
	 | INT32 {}
	 | INT64 {}
	 ;

tpa : tpa VIRG type NAME {}
	 | tpa VIRG type CHEVOPEN CHEVCLOSE NAME tpa
	 | /* epsilon */ {}
	 ;	 

pa :  type NAME tpa {}
	 | type CHEVOPEN CHEVCLOSE NAME tpa {}
	 ;


instruction : decdef {}
	 | PUTCHAR COPEN expression CCLOSE {}
	 | GETCHAR COPEN expression CCLOSE {}
	 | BREAK {}
	 | expression {}
	 | RETURN expression {}
	 ;

el : ELSE CHEVOPEN bloc CHEVCLOSE {}
	 | ELSE CHEVOPEN bloc CHEVCLOSE {}
	 | ELSE instruction {}
	 | /* epsilon */ {}
	 ;

eli : ELSE IF COPEN expression CCLOSE CHEVOPEN bloc CHEVCLOSE eli el {}
	 | ELSE IF COPEN expression CCLOSE instruction eli el {}
	 | /* epsilon */ {}
	 ;

structure : IF COPEN expression CCLOSE CHEVOPEN bloc CHEVCLOSE eli el {}
	 | IF COPEN expression CCLOSE instruction eli el {}
	 | FOR COPEN expression POINTVIR expression POINTVIR expression CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | FOR COPEN expression POINTVIR expression POINTVIR expression CCLOSE instruction {}
	 | WHILE COPEN expression CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | WHILE COPEN expression CCLOSE instruction {}
	 ;

bloc : CHEVOPEN bloc CHEVCLOSE {}
	 | bloc instruction {}
	 | bloc structure {}
	 | /* epsilon */ {}
	 ;

fonction : type NAME COPEN pa CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | type NAME COPEN CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | type NAME COPEN VOID CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | VOID NAME COPEN pa CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | VOID NAME COPEN CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | VOID NAME COPEN VOID CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 ;



expression :  expression PLUS expression { /* $$ = new ExpressionBinaire($1, $3, PLUS); */ }
     | expression MULT expression  { /* $$ = new ExpressionBinaire($1, $3, MULT); */ }
     | expression DIV expression  { /* $$ = new ExpressionBinaire($1, $3, DIV); */ }
     | expression MOINS expression{ /* $$ = new ExpressionBinaire($1, $3, MOINS); */ }
     | expression MOD expression { /* $$ = new ExpressionBinaire($1, $3, MOD); */ }
     | POPEN expression PCLOSE{ $$ = $2; }
     | expression DINF expression{  }
     | expression DSUP expression{  }
     | NOT expression{  }
     | expression AND expression{ /* $$ = new ExpressionBinaire($1, $3, AND); */ }
     | expression DAND expression{ /* $$ = new ExpressionBinaire($1, $3, DAND); */ }
     | expression OR expression{ /* $$ = new ExpressionBinaire($1, $3, OR); */ }
     | expression DOR expression{ /* $$ = new ExpressionBinaire($1, $3, DOR); */ }
     | expression XOR expression{ /* $$ = new ExpressionBinaire($1, $3, XOR); */ }
     | expression SUP expression{ /* $$ = new ExpressionBinaire($1, $3, SUP); */ }
     | expression INF expression{ /* $$ = new ExpressionBinaire($1, $3, INF); */ }
     | expression INFEQ expression{ /* $$ = new ExpressionBinaire($1, $3, INFEQ); */ }
     | expression SUPEQ expression{ /* $$ = new ExpressionBinaire($1, $3, SUPEQ); */ }
     | expression DEGAL expression{ /* $$ = new ExpressionBinaire($1, $3, DEGAL); */ }
     | expression DIFF expression{ /* $$ = new ExpressionBinaire($1, $3, DIFF); */ }
     | NAME {}
     | NAME COPEN expression CCLOSE  {}
     | NVALUE {}
     | CVALUE {}
     | affectation {}
     | appfct {}
     ;

affectation : NAME EGAL expression {}
	 | NAME COPEN expression CCLOSE EGAL expression {}
	 | NAME DPLUS {}
	 | DPLUS NAME {}
	 | NAME DMOINS {}
	 | DMOINS NAME {}
	 | NAME PLUSEQ expression {}
	 | NAME MOINSEQ expression {} 
	 | NAME MULTEQ expression {}
	 | NAME DIVEQ expression {}
	 | NAME MODEQ expression {}
	 | NAME ANDEQ expression {}
	 | NAME OREQ expression {}
	 ;     

lee : expression lee {}
	 | /* epsilon */ {}
	 ;

le : expression lee {}
	 | /* epsilon */ {}
	 ;

appfct : NAME COPEN le CCLOSE {}
	 ;

decdef : type NAME {}
	 | type NAME EGAL expression {}
	 | type NAME COPEN NVALUE CCLOSE {}
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