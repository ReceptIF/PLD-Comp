#include "VariableTableau.h"

VariableTableau::~VariableTableau()
{

}

std::string VariableTableau::toSmallString() {
  return nomVariable+"["+indice->toSmallString()+"]";
}
