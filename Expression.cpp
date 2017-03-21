#include "Expression.h"

Expression::Expression()
{
  this->type = -1;
}

Expression::~Expression()
{

}

int Expression getType() {
  return this->type;
}
