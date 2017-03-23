#include "Expression.h"

Expression::Expression()
{
  this->type = -1;
}

Expression::~Expression()
{

}

int Expression::getType() {
  return this->type;
}

std::string Expression::stringifySymbole(int symb) {
  
  std::string str;
  
  switch(symb) {
    case EGAL :   str = "="; break;
    case PLUS :   str = "+"; break;
    case MULT :   str = "*"; break;
    case DIV :    str = "/"; break;
    case MOINS :  str = "-"; break;
    case AND :    str = "&"; break;
    case DAND :   str = "&&"; break;
    case OR :     str = "|"; break;
    case DOR :    str = "||"; break;
    case DEGAL :  str = "=="; break;
    case INFEQ :  str = "<="; break;
    case SUPEQ :  str = ">="; break;
    case DIFF :   str = "!="; break;
    case MOD :    str = "%"; break;
    case XOR :    str = "^"; break;
    case PLUSEQ : str = "+="; break;
    case MULTEQ : str = "*="; break;
    case DIVEQ :  str = "/="; break;
    case MOINSEQ :str = "-="; break;
    case DPLUS :  str = "++"; break;
    case DMOINS : str = "--"; break;
    case NOT :    str = "!"; break;
    case MODEQ :  str = "%="; break;
    case DSUP :   str = ">>"; break;
    case DINF :   str = "<<"; break;
    case INF :    str = "<"; break;
    case SUP :    str = ">"; break;
    case ANDEQ :  str = "&="; break;
    case OREQ :   str = "|="; break;
    case DMOINSAVANT : str = "--"; break;
    case DPLUSAVANT :  str = "++"; break;
  }
  
  return str;
  
}
