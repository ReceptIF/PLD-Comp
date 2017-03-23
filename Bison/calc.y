%{
#include <iostream>
#include <string>

#include "../AppelFonction.h"
#include "../Bloc.h"
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
#include "../StructCond.h"
#include "../Structure.h"
#include "../Type.h"
#include "../Variable.h"
#include "../VariableSimple.h"
#include "../VariableTableau.h"
#include "../While.h"


int yylex(void);
void yyerror(Programme*, const char *);
int yylexpression(void);

%}
%union {
   int ival; 
   double dval;
   char* cval;

   AppelFonction *appFonct;
   Bloc *block;
   Declaration *decl;
   Expression *expr;
   Fonction *fonct;
   For *bouclefor;
   Instruction *instru;
   Structure* structu;
   Programme *prog;
   
   std::list<Declaration *> *decList;
}

%token EGAL PLUS MULT DIV MOINS AND DAND OR DOR DEGAL INFEQ SUPEQ DIFF MOD XOR PLUSEQ MULTEQ DIVEQ MOINSEQ DPLUS DMOINS NOT MODEQ DSUP DINF INF SUP ANDEQ OREQ IF ELSE WHILE FOR CHAR INT32 INT64 VOID POINTVIR CHEVOPEN CHEVCLOSE POPEN PCLOSE COPEN CCLOSE VIRG PUTCHAR GETCHAR RETURN BREAK

%token <cval> NAME
%token <ival> NVALUE
%token <ival> CVALUE
%token <ival> INCL

%type <prog> programme
%type <fonct> fonction
%type <appFonct> appfct
%type <block> bloc
%type <decl> decdef
%type <e> el
%type <expr> expression
%type <instru> instruction
%type <e> le
%type <e> lee
%type <decList> pa
%type <structu> structure
%type <ival> type
%type <decList> tpa

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

%parse-param { Programme * prog }

%%

/*axiome : expression { *resultat = $1; }
     ;*/

programme : programme INCL      { prog = $1; }
	      | programme fonction    { prog->AjouteFonction($2); $$ = $1; }
	      | /* epsilon */         { }
	      ;


fonction : type NAME POPEN pa PCLOSE CHEVOPEN bloc CHEVCLOSE  { Fonction *f = new Fonction($1, $7, $2); f->setParametres($4); $$ = f; }
	     | type NAME POPEN PCLOSE CHEVOPEN bloc CHEVCLOSE       { $$ = new Fonction($1, $6, $2);  }
	     | type NAME POPEN VOID PCLOSE CHEVOPEN bloc CHEVCLOSE  { $$ = new Fonction($1, $7, $2);  }
       | VOID NAME POPEN pa PCLOSE CHEVOPEN bloc CHEVCLOSE    { Fonction *f = new Fonction(VOID, $7, $2); f->setParametres($4); $$ = f; }
	     | VOID NAME POPEN PCLOSE CHEVOPEN bloc CHEVCLOSE       { $$ = new Fonction(VOID, $6, $2); }
	     | VOID NAME POPEN VOID PCLOSE CHEVOPEN bloc CHEVCLOSE  { $$ = new Fonction(VOID, $7, $2); }
	     ;

bloc : CHEVOPEN bloc CHEVCLOSE  { $$ = $2; }
	 | bloc instruction         { $1->AjouteInstruction($2); $$ = $1; }
	 | bloc structure           { $1->AjouteInstruction($2); $$ = $1; }
	 | /* epsilon */            { $$ = new Bloc(); }
	 ;

instruction : decdef POINTVIR                          { $$ = $1; }
	        | PUTCHAR COPEN expression CCLOSE POINTVIR   { }
	        | GETCHAR COPEN expression CCLOSE POINTVIR   { }
	        | BREAK POINTVIR                             { }
	        | expression POINTVIR                        { }
	        | RETURN expression POINTVIR                 { }
	        ;

structure : IF POPEN expression PCLOSE CHEVOPEN bloc CHEVCLOSE  el                                      { }
	      | IF POPEN expression PCLOSE instruction el                                                   { }
	      | FOR POPEN expression POINTVIR expression POINTVIR expression PCLOSE CHEVOPEN bloc CHEVCLOSE { $$ = new For($3, $5, $7, $10); }
	      | FOR POPEN expression POINTVIR expression POINTVIR expression PCLOSE instruction             { $$ = new For($3, $5, $7, $9); }
	      | WHILE POPEN expression PCLOSE CHEVOPEN bloc CHEVCLOSE                                       { }
	      | WHILE POPEN expression PCLOSE instruction                                                   { }
	      ;


tpa : tpa VIRG type NAME                        { Declaration *d = new Declaration($4,$3); $1->push_back(d); $$ = $1; }
	| tpa VIRG type CHEVOPEN CHEVCLOSE NAME tpa { }
	| /* epsilon */                             { $$ = new std::list<Declaration *> (); }
	;

pa : type NAME tpa                      { Declaration *d = new Declaration($2,$1); $3->push_back(d); $$ = $3; }
   | type CHEVOPEN CHEVCLOSE NAME tpa   { }
   ;


el : ELSE CHEVOPEN bloc CHEVCLOSE                               { }
   | ELSE instruction                                           { }
   | ELSE IF POPEN expression PCLOSE CHEVOPEN bloc CHEVCLOSE el { }
   | ELSE IF POPEN expression PCLOSE instruction el             { }
   | /* epsilon */                                              { }
   ;

expression :  NAME { $$ = new ExpressionVariable($1); }
     | NVALUE { }
     | CVALUE {}
	 | expression PLUS expression {  $$ = new ExpressionBinaire($1, $3, PLUS); }
     | expression MULT expression  { $$ = new ExpressionBinaire($1, $3, MULT); }
     | expression DIV expression  { $$ = new ExpressionBinaire($1, $3, DIV); }
     | expression MOINS expression{ $$ = new ExpressionBinaire($1, $3, MOINS); }
     | expression MOD expression { $$ = new ExpressionBinaire($1, $3, MOD); }
     | POPEN expression PCLOSE{  $$ = $2;  }
     | expression DINF expression { $$ = new ExpressionBinaire($1, $3, DINF); }
     | expression DSUP expression { $$ = new ExpressionBinaire($1, $3, DSUP); }
     | NOT expression{ $$ = new ExpressionUnaire($2, NOT, 1); }
     | expression AND expression{ $$ = new ExpressionBinaire($1, $3, AND); }
     | expression DAND expression{ $$ = new ExpressionBinaire($1, $3, DAND); }
     | expression OR expression{ $$ = new ExpressionBinaire($1, $3, OR); }
     | expression DOR expression{ $$ = new ExpressionBinaire($1, $3, DOR); }
     | expression XOR expression{ $$ = new ExpressionBinaire($1, $3, XOR); }
     | expression SUP expression{ $$ = new ExpressionBinaire($1, $3, SUP); }
     | expression INF expression{ $$ = new ExpressionBinaire($1, $3, INF); }
     | expression INFEQ expression{ $$ = new ExpressionBinaire($1, $3, INFEQ); }
     | expression SUPEQ expression{ $$ = new ExpressionBinaire($1, $3, SUPEQ); }
     | expression DEGAL expression{ $$ = new ExpressionBinaire($1, $3, DEGAL); }
     | expression DIFF expression{ $$ = new ExpressionBinaire($1, $3, DIFF); }
     | NAME COPEN expression CCLOSE  {}
     | NAME EGAL expression { ExpressionVariable* e = new ExpressionVariable((char*)NAME) ; $$ = new ExpressionBinaire(e, $3, EGAL); }
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

lee : lee VIRG expression { }
	| /* epsilon */       { }
	;

le : expression lee { }
   | /* epsilon */  { }
   ;

appfct : NAME POPEN le PCLOSE {}
	   ;

decdef : type NAME                      { $$ = new Declaration((char*)NAME, $1); }
	   | type NAME EGAL expression      { }
	   | type NAME COPEN NVALUE CCLOSE  { }
	   ;

type : CHAR  { $$ = CHAR; }
	 | INT32 { $$ = INT32;}
	 | INT64 { $$ = INT64; }
	 ;


%%

void yyerror(Programme* zz, const char * s)
{
	std::cout << "[ERREUR] Programme : " << s << std::endl << zz->toString() << std::endl;
}

extern int yydebug;

int main(void) {
   //yydebug = 1;
   Programme* prog = new Programme();

   yyparse(prog);

   delete prog;

   int a;
   std::cout << "[Fin du programme]" << std::endl;
   std::cin >> a;
   return 0;
}
