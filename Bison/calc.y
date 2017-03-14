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

%type <ival> affectation
%type <ival> bloc
%type <ival> decdef
%type <ival> el
%type <ival> eli
%type <ival> expression
%type <ival> fonction
%type <ival> instruction
%type <ival> programme
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

type : CHAR {}
	 | INT32 {}
	 | INT64 {}
	 ;

expression : expression PLUS expression {  }
     | expression MULT expression  {  }
     | expression DIV expression  {  }
     | expression MOINS expression{  }
     | expression MOD expression {  }
     | COPEN expression CCLOSE{  }
     | expression DINF expression{  }
     | expression DSUP expression{  }
     | NOT expression{  }
     | expression AND expression{  }
     | expression DAND expression{  }
     | expression OR expression{  }
     | expression DOR expression{  }
     | expression XOR expression{  }
     | expression SUP expression{  }
     | expression INF expression{  }
     | expression INFEQ expression{  }
     | expression SUPEQ expression{  }
     | expression DEGAL expression{  }
     | expression DIFF expression{  }
     | NAME {}
     | NAME COPEN expression CCLOSE  {}
     | NVALUE { }
     | CVALUE { }
     | affectation { }
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

bloc : CHEVOPEN bloc CHEVCLOSE {}
	 | bloc instruction {}
	 | bloc structure {}
	 | /* epsilon */ {}
	 ;

decdef : type NAME { }
	 | type NAME EGAL expression {}
	 | type NAME COPEN NVALUE CCLOSE { }
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


fonction : type NAME COPEN pa CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | type NAME COPEN CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | type NAME COPEN VOID CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | VOID NAME COPEN pa CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | VOID NAME COPEN CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | VOID NAME COPEN VOID CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 ;

instruction : decdef {}
	 | affectation {}
	 | PUTCHAR COPEN expression CCLOSE {}
	 | GETCHAR COPEN expression CCLOSE {}
	 | BREAK {}
	 | RETURN expression {}
	 ;

structure : IF COPEN expression CCLOSE CHEVOPEN bloc CHEVCLOSE eli el {}
	 | IF COPEN expression CCLOSE instruction eli el {}
	 | FOR COPEN expression POINTVIR expression POINTVIR expression CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | FOR COPEN expression POINTVIR expression POINTVIR expression CCLOSE instruction {}
	 | WHILE COPEN expression CCLOSE CHEVOPEN bloc CHEVCLOSE {}
	 | WHILE COPEN expression CCLOSE instruction {}
	 ;



tpa : tpa VIRG type NAME {}
	 | tpa VIRG type CHEVOPEN CHEVCLOSE NAME tpa
	 | /* epsilon */ {}
	 ;

programme : programme INCL {}
	 | programme fonction {}
	 | /* epsilon */ {}
	 ;

pa :  type NAME tpa { }
	 | type CHEVOPEN CHEVCLOSE NAME tpa {}
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

