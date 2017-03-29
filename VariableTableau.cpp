#include "VariableTableau.h"

VariableTableau::~VariableTableau()
{
  delete indice;
}

std::string VariableTableau::toSmallString() {
  return nomVariable+"["+indice->toSmallString()+"]";
}
