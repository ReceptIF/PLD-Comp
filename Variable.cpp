#include "Variable.h"

Variable::Variable(std::string nomVar)
{
  this->nomVariable = nomVar;
}

Variable::~Variable()
{

}

std::string Variable::getNom() {
  return nomVariable;
}

void Variable::setNom(std::string nom) {
  nomVariable = nom;
}
