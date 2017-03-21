#include "ExpressionVariable.h"

ExpressionVariable::ExpressionVariable(std::string nomVariable)
{
  this->variable = new Variable(nomVariable);
}

ExpressionVariable::~ExpressionVariable()
{
  delete this->variable;
}

void ExpressionVariable::typage() {
  
  // TODO BUT NEED TO DO THE PORTEE
  this->type = INT32;
  
}
