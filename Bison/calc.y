%{
#include "../Expression.h"

#include <iostream>
#include <string>

int yylex(void);
void yyerror(int*, Expression**, const char *);
int yylexpression(void);

%}
%union {
   int ival; 
   double dval;
   Expression *e;
}

%token EGAL PLUS MULT DIV MOINS AND DAND OR DOR DEGAL INFEQ SUPEQ DIFF MOD XOR PLUSEQ MULTEQ DIVEQ MOINSEQ DPLUS DMOINS NOT MODEQ DSUP DINF INF SUP ANDEQ OREQ IF ELSE WHILE FOR CHAR INT32 INT64 VOID POINTVIR CHEVOPEN CHEVCLOSE POPEN PCLOSE COPEN CCLOSE VIRG PUTCHAR GETCHAR RETURN BREAK

%token <ival> NAME
%token <ival> NVALUE
%token <ival> CVALUE
%token <ival> INCL

%type <e> programme
%type <e> fonction
%type <e> appfct
%type <e> bloc
%type <e> decdef
%type <e> el
%type <e> expression
%type <e> instruction
%type <e> le
%type <e> lee
%type <e> pa
%type <e> structure
%type <e> type
%type <e> tpa

%left POPEN PCLOSE COPEN CCLOSE DPLUS DMOINS 
%right NOT NAME NVALUE CVALUE DPLUSAVANT DMOINSAVANT
%left MULT DIV MOD
%left PLUS MOINS
%left DSUP DINF
%left SUP INF SUPEQ INFEQ
%left DEGAL DIFF
%left AND
%left XOR
%left OR
%left DAND
%left DOR
%right EGAL PLUSEQ MULTEQ DIVEQ MOINSEQ MODEQ ANDEQ OREQ
%left VIRG

%parse-param { int * resultat } { Expression ** e }

%%

/*axiome : expression { *resultat = $1; }
     ;*/ 

programme : programme INCL {}
	 | programme fonction {}
	 | /* epsilon */ {}
	 ;


fonction : type NAME POPEN pa PCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | type NAME POPEN PCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | type NAME POPEN VOID PCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | VOID NAME POPEN pa PCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | VOID NAME POPEN PCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | VOID NAME POPEN VOID PCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 ;

bloc : CHEVOPEN bloc CHEVCLOSE {}
	 | bloc instruction {}
	 | bloc structure {}
	 | /* epsilon */ {}
	 ;	 

instruction : decdef {}
	 | PUTCHAR COPEN expression CCLOSE {}
	 | GETCHAR COPEN expression CCLOSE {}
	 | BREAK {}
	 | expression {}
	 | RETURN expression {}
	 ;

structure : IF POPEN expression PCLOSE CHEVOPEN bloc CHEVCLOSE  el {}
	 | IF POPEN expression PCLOSE instruction el {}
	 | FOR POPEN expression POINTVIR expression POINTVIR expression PCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | FOR POPEN expression POINTVIR expression POINTVIR expression PCLOSE instruction {}
	 | WHILE POPEN expression PCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | WHILE POPEN expression PCLOSE instruction {}
	 ;


tpa : tpa VIRG type NAME {}
	 | tpa VIRG type CHEVOPEN CHEVCLOSE NAME tpa {}
	 | /* epsilon */ {}
	 ;	 

pa :  type NAME tpa {}
	 | type CHEVOPEN CHEVCLOSE NAME tpa {}
	 ;


el : ELSE CHEVOPEN bloc CHEVCLOSE {}
	 | ELSE instruction {}
	 | ELSE IF POPEN expression PCLOSE CHEVOPEN bloc CHEVCLOSE el {}
	 | ELSE IF POPEN expression PCLOSE instruction el {}
	 | /* epsilon */ {}
	 ;

expression :  NAME {} 
     | NVALUE {}
     | CVALUE {}
	 | expression PLUS expression { /* $$ = new ExpressionBinaire($1, $3, PLUS); */ }
     | expression MULT expression  { /* $$ = new ExpressionBinaire($1, $3, MULT); */ }
     | expression DIV expression  { /* $$ = new ExpressionBinaire($1, $3, DIV); */ }
     | expression MOINS expression{ /* $$ = new ExpressionBinaire($1, $3, MOINS); */ }
     | expression MOD expression { /* $$ = new ExpressionBinaire($1, $3, MOD); */ }
     | POPEN expression PCLOSE{ /* $$ = $2; */ }
     | expression DINF expression {  }
     | expression DSUP expression {  }
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
     | NAME COPEN expression CCLOSE  {}
     | NAME EGAL expression {}
	 | NAME COPEN expression CCLOSE EGAL expression {}
	 | NAME DPLUS {}
	 | DPLUS NAME %prec DPLUSAVANT {}
	 | NAME DMOINS {}
	 | DMOINS NAME %prec DMOINSAVANT {}
	 | NAME PLUSEQ expression {}
	 | NAME MOINSEQ expression {} 
	 | NAME MULTEQ expression {}
	 | NAME DIVEQ expression {}
	 | NAME MODEQ expression {}
	 | NAME ANDEQ expression {}
	 | NAME OREQ expression {}
     | appfct {}
     ;   

lee : lee VIRG expression {}
	 | /* epsilon */ {}
	 ;

le : expression lee {}
	 | /* epsilon */ {}
	 ;

appfct : NAME POPEN le PCLOSE {}
	 ;

decdef : type NAME {}
	 | type NAME EGAL expression {}
	 | type NAME COPEN NVALUE CCLOSE {}
	 ;

type : CHAR {}
	 | INT32 {}
	 | INT64 {}
	 ;


%%

void yyerror(int* a, Expression** b, const char * s)
{
	std::cout << s << std::endl;
}

int main(void) {
   int res = 0;
   Expression* e = 0;

   yyparse(&res, &e);

   std::cout << "Result :" << res << std::endl;

   delete e;

   return 0;
}