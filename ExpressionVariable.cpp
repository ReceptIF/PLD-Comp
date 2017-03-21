#include "ExpressionVariable.h"

ExpressionVariable::ExpressionVariable(std::string nomVariable)
{
  this->variable = new Variable(nomVariable);
}

ExpressionVariable::~ExpressionVariable()
{
  delete this->variable;
}
