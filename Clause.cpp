#include "Clause.h"

Clause::~Clause()
{

}

Expression *Clause::getExpression() {
  return this->expression;
}

Bloc *Clause::getBloc() {
  return this->bloc;
}
