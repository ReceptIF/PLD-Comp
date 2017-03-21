#include "ExpressionUnaire.h"

ExpressionUnaire::ExpressionUnaire()
{

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
