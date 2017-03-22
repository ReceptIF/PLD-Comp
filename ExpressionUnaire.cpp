#include "ExpressionUnaire.h"

ExpressionUnaire::ExpressionUnaire(Expression *e, int symb, int pref)
{
  this->expression1 = e;
  this->symbole = symb;
  this->prefixe = pref;
}

ExpressionUnaire::~ExpressionUnaire()
{

}

void ExpressionUnaire::setExpression1(Expression* &expression)
{
	expression1 = expression;
}

void ExpressionUnaire::setSymbole(int &symbole)
{
	symbole = symbole;
}

void ExpressionUnaire::setPrefixe(int &prefixe)
{
	prefixe = prefixe;
}

Expression *ExpressionUnaire::getExpression1()
{
	return expression1;
}

int ExpressionUnaire::getSymbole()
{
	return symbole;
}

int ExpressionUnaire::getPrefixe()
{
	return prefixe;
}

void ExpressionUnaire::typage() {
  
  this->expression1->typage();
  this->type = expression1->getType();
  
}
