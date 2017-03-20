#include "ExpressionUnaire.h"

ExpressionUnaire::ExpressionUnaire()
{

}

ExpressionUnaire::~ExpressionUnaire()
{

}

void setExpression1(Expression &expression)
{
	expression1 = expression;
}

void setSymbole(int &symbole)
{
	symbole = symbole;
}

void setPrefixe(int &prefixe)
{
	prefixe = prefixe;
}

Expression getExpression1()
{
	return expression1;
}

int getSymbole()
{
	return symbole;
}

int getPrefixe()
{
	return prefixe;
}