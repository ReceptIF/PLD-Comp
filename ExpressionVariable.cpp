#include "ExpressionVariable.h"

ExpressionVariable::ExpressionVariable(std::string nomVariable)
{
  this->variable = new VariableSimple(nomVariable);
}

ExpressionVariable::ExpressionVariable(std::string nomVariable, Expression *e)
{
  this->variable = new VariableTableau(nomVariable,e);
}

ExpressionVariable::~ExpressionVariable()
{
  delete this->variable;
}

void ExpressionVariable::typage() {
  
  // TODO BUT NEED TO DO THE PORTEE
  this->type = INT32;
  
}

std::string ExpressionVariable::toString() {
  return "[I] ExprVar | "+variable->toSmallString()+"\r\n";
}

std::string ExpressionVariable::toSmallString() {
  return variable->toSmallString();
}

