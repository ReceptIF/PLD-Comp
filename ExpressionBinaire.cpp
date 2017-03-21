#include "ExpressionBinaire.h"

ExpressionBinaire::ExpressionBinaire()
{

}

ExpressionBinaire::~ExpressionBinaire()
{

}

void setExpression1(Expression* expression)
{
	expression1 = expression;
}

void setExpression2(Expression* expression)
{
	expression2 = expression;
}

void setSymbole(int &symbole)
{
	symbole = symbole;
}

Expression getExpression1()
{
	return expression1;
}

Expression getExpression2()
{
	return expression2;
}

int getSymbole()
{
	return symbole;
}