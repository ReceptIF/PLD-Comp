#include "Clause.h"

Clause::Clause(Expression *e, Instruction *i)
{
  this->expression = e;
  
  Bloc *b = new Bloc();
  b->AjouteInstruction(i);
  
  this->bloc= b;
  
}

Clause::~Clause()
{

}

Expression *Clause::getExpression() {
  return this->expression;
}

Bloc *Clause::getBloc() {
  return this->bloc;
}
