#include "ExpressionUnaire.h"

ExpressionUnaire::ExpressionUnaire(Expression *e, int symb, int pref)
{
  this->expression1 = e;
  this->symbole = symb;
  this->prefixe = pref;
}

ExpressionUnaire::~ExpressionUnaire()
{
    delete expression1;
}

void ExpressionUnaire::setExpression1(Expression* expression)
{
	expression1 = expression;
}

void ExpressionUnaire::setSymbole(int symbole)
{
	this->symbole = symbole;
}

void ExpressionUnaire::setPrefixe(int prefixe)
{
	this->prefixe = prefixe;
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

std::string ExpressionUnaire::toString() {
  if(!prefixe) {
    return "[I] ExprUnaire | "+expression1->toSmallString()+stringifySymbole(symbole)+"\r\n";
  }else {
    return "[I] ExprUnaire | "+stringifySymbole(symbole)+expression1->toSmallString()+"\r\n";
  }
}

std::string ExpressionUnaire::toSmallString() {
  if(prefixe) {
    return expression1->toSmallString()+stringifySymbole(symbole);
  }else {
    return stringifySymbole(symbole)+expression1->toSmallString();
  }
}

void ExpressionUnaire::resoudrePortees(std::list<std::string> *varStack, std::map<std::string,Declaration *> *varMap, std::list<std::string> *fctStack) {
  expression1->resoudrePortees(varStack, varMap, fctStack);
}

IRVar *ExpressionUnaire::getIR(BasicBlock *bb) {
  return nullptr;
}
