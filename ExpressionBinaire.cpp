#include "ExpressionBinaire.h"

ExpressionBinaire::ExpressionBinaire()
{

}

ExpressionBinaire::~ExpressionBinaire()
{

}

void ExpressionBinaire::setExpression1(Expression* expression)
{
	expression1 = expression;
}

void ExpressionBinaire::setExpression2(Expression* expression)
{
	expression2 = expression;
}

void ExpressionBinaire::setSymbole(int &symbole)
{
	symbole = symbole;
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
