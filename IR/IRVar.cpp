#include "IRVar.h"

IRVar::~ IRVar()
{
    
}

std::string IRVar::getName() {
  return this->name;
}

void IRVar::setOffset(int off) {
  this->offset=off;
}

int IRVar::getType() {
  return this->type;
}
