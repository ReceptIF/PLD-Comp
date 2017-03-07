%{
#include <stdio.h>
void yyerror(int *, const char *);
int yylex(void);
%}
%union {
   int ival; 
}

%token EGAL PLUS MULT DIV MOINS AND DAND OR DOR DEGAL INFEQ SUPEQ DIFF MOD XOR PLUSEQ MULTEQ DIVEQ MOINSEQ DPLUS DMOINS NOT MODEQ DSUP DINF INF SUP ANDEQ OREQ IF ELSE WHILE FOR CHAR INT32 INT64 VOID POINTVIR CHEVOPEN CHEVCLOSE POPEN PCLOSE COPEN CCLOSE VIRG PUTCHAR GETCHAR RETURN BREAK

%token <ival> NAME
%token <ival> NVALUE
%token <ival> CVALUE
%token <ival> INCL

%type <ival> a
%type <ival> b
%type <ival> d
%type <ival> el
%type <ival> eli
%type <ival> ex
%type <ival> f
%type <ival> i
%type <ival> p
%type <ival> pa
%type <ival> s
%type <ival> t
%type <ival> tpa

%left MOINS PLUS
%left MULT DIV

%parse-param { int * resultat }

%%

/*axiome : ex { *resultat = $1; }
     ;*/ 

a : NAME EGAL ex {}
	 | NAME COPEN ex CCLOSE EGAL ex {}
	 | NAME DPLUS {}
	 | DPLUS NAME {}
	 | NAME DMOINS {}
	 | DMOINS NAME {}
	 | NAME PLUSEQ ex {}
	 | NAME MOINSEQ ex {} 
	 | NAME MULTEQ ex {}
	 | NAME DIVEQ ex {}
	 | NAME MODEQ ex {}
	 | NAME ANDEQ ex {}
	 | NAME OREQ ex {}
	 ;

b : CHEVOPEN b CHEVCLOSE {}
	 | b i {}
	 | b s {}
	 | /* epsilon */ {}
	 ;

el : ELSE CHEVOPEN b CHEVCLOSE {}
	 | ELSE CHEVOPEN b CHEVCLOSE {}
	 | ELSE i {}
	 | /* epsilon */ {}
	 ;

eli : ELSE IF COPEN ex CCLOSE CHEVOPEN b CHEVCLOSE eli el {}
	 | ELSE IF COPEN ex CCLOSE i eli el {}
	 | /* epsilon */ {}
	 ;

ex : ex PLUS ex {  }
     | ex MULT ex  {  }
     | ex DIV ex  {  }
     | ex MOINS ex{  }
     | ex MOD ex {  }
     | OPEN ex CLOSE{  }
     | ex DINF ex{  }
     | ex DSUP ex{  }
     | NOT ex{  }
     | ex AND ex{  }
     | ex DAND ex{  }
     | ex OR ex{  }
     | ex DOR ex{  }
     | ex XOR ex{  }
     | ex SUP ex{  }
     | ex INF ex{  }
     | ex INFEQ ex{  }
     | ex SUPEQ ex{  }
     | ex DEGAL ex{  }
     | ex DIFF ex{  }
     | NAME {}
     | NAME COPEN ex CCLOSE  {}
     | NVALUE { }
     | CVALUE { }
     | a { }
     ;

d : t NAME { }
	 | t NAME EGAL ex {}
	 | t NAME COPEN NVALUE CCLOSE { }
	 ;

f : t NAME COPEN pa CCLOSE CHEVOPEN b CHEVCLOSE {}
	 | t NAME COPEN CCLOSE CHEVOPEN b CHEVCLOSE {}
	 | t NAME COPEN VOID CCLOSE CHEVOPEN b CHEVCLOSE {}
	 | VOID NAME COPEN pa CCLOSE CHEVOPEN b CHEVCLOSE {}
	 | VOID NAME COPEN CCLOSE CHEVOPEN b CHEVCLOSE {}
	 | VOID NAME COPEN VOID CCLOSE CHEVOPEN b CHEVCLOSE {}
	 ;

i : d {}
	 | a {}
	 | PUTCHAR COPEN ex CCLOSE {}
	 | GETCHAR COPEN ex CCLOSE {}
	 | BREAK {}
	 | RETURN ex {}
	 ;

s : IF COPEN ex CCLOSE CHEVOPEN b CHEVCLOSE eli el {}
	 | IF COPEN ex CCLOSE i eli el {}
	 | FOR COPEN ex POINTVIR ex POINTVIR ex CCLOSE CHEVOPEN b CHEVCLOSE {}
	 | FOR COPEN ex POINTVIR ex POINTVIR ex CCLOSE i {}
	 | WHILE COPEN ex CCLOSE CHEVOPEN b CHEVCLOSE {}
	 | WHILE COPEN ex CCLOSE i {}
	 ;

t : CHAR {}
	 | INT32 {}
	 | INT64 {}
	 ;

tpa : tpa VIRG t NAME {}
	 | tpa VIRG t CHEVOPEN CHEVCLOSE NAME tpa
	 | /* epsilon */ {}
	 ;

p : p INCL {}
	 | p f {}
	 | /* epsilon */ {}
	 ;

pa :  t NAME tpa { }
	 | t CHEVOPEN CHEVCLOSE NAME tpa {}
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

