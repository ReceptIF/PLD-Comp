#include "ExpressionBinaire.h"
#include "Bison/calc.tab.h"

ExpressionBinaire::ExpressionBinaire(Expression *e1, Expression *e2, int symb)
{
  this->expression1 = e1;
  this->expression2 = e2;
  this->symbole = symb;
}

ExpressionBinaire::~ExpressionBinaire()
{
	delete this->expression1;
	delete this->expression2;
}

void ExpressionBinaire::setExpression1(Expression* expression)
{
	this->expression1 = expression;
}

void ExpressionBinaire::setExpression2(Expression* expression)
{
	this->expression2 = expression;
}

void ExpressionBinaire::setSymbole(int &symbole)
{
	this->symbole = symbole;
}

Expression *ExpressionBinaire::getExpression1()
{
	return expression1;
}

Expression *ExpressionBinaire::getExpression2()
{
	return expression2;
}

int ExpressionBinaire::getSymbole()
{
	return symbole;
}

void ExpressionBinaire::typage() {
  
  this->expression1.typage();
  this->expression2.typage();
  
  int type1 = expression1.getType();
  int type2 = expression2.getType();
  
  int resType;
  
  if(symbole == EGAL) {
    // Affectation
    resType = type2;
    
  } else if(symbole == PLUS || symbole == MULT || symbole == DIV || 
            symbole == MOINS || symbole == PLUS || symbole == MOD ||
            symbole == PLUSEQ || symbole == MULTEQ || symbole == DIVEQ ||
            symbole == MOINSEQ || symbole == MODEQ) {
    // Opération calculatoire
    if(type1 == INT64 && type2 == INT64) {
      restype = INT64;
    } else if((type1 == INT64 && type2 == INT32) || (type1 == INT32 && type2 == INT64)) {
      restype = INT64;
    } else if((type1 == INT64 && type2 == CHAR) || (type1 == CHAR && type2 == INT64)) {
      restype = INT64;
    } else if(type1 == INT32 && type2 == INT32) {
      restype = INT32;
    } else if((type1 == CHAR && type2 == INT32) || (type1 == INT32 && type2 == CHAR)) {
      restype = INT32;
    } else if(type1 == CHAR && type2 == CHAR) {
      restype = CHAR;
    } 
    
  } else if(symbole == DAND || symbole == DOR || symbole == DEGAL || 
            symbole == INFEQ || symbole == SUPEQ || symbole == DIFF || 
            symbole == INF || symbole == SUP || symbole == ANDEQ || 
            symbole == OREQ || symbole == SUPEQ || symbole == DIFF) {
    // Opération booléenne
    resType = INT32;
    
  } else if(symbole == AND || symbole == OR || symbole == XOR) {
    // Opération bit à bit
    resType = INT64;
  
  }else if(symbole == DSUP || symbole == DINF) {
    // Opération de shift
    resType = type1;
    
  }
  
  this->type = resType;
}
