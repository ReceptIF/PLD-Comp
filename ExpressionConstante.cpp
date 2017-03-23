#include "ExpressionConstante.h"

ExpressionConstante::ExpressionConstante(int aType, int aValeur)
{
  this->type = aType;
  this->valeur = aValeur;
}

ExpressionConstante::~ExpressionConstante()
{

}

void ExpressionConstante::typage() {
  // doNothing
}

std::string ExpressionConstante::toString() {
  return "[I] ExpressionConstante";
}
