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

int IRVar::getOffset() {
  return this->offset;
}

int IRVar::isTmp() {
  return this->tmp;
}

void IRVar::setSize(int aSize) {
  this->size = aSize;
}

int IRVar::getSize() {
  return this->size;
}

