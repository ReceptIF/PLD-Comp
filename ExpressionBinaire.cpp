#include "ExpressionBinaire.h"

ExpressionBinaire::ExpressionBinaire(Expression *e1, Expression *e2, int symb)
{
  this->expression1 = e1;
  this->expression2 = e2;
  this->symbole = symb;
}

ExpressionBinaire::~ExpressionBinaire()
{

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
