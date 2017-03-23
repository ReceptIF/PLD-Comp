#include "ExpressionConstante.h"

ExpressionConstante::ExpressionConstante(int aType, int aValeur)
{
  this->type = aType;
  this->valeur = aValeur;
  std::cout << "Const "+valeur << std::endl;
}

ExpressionConstante::~ExpressionConstante()
{

}

void ExpressionConstante::typage() {
  // doNothing
}

std::string ExpressionConstante::toString() {
  std::string print = "[I] ExprConst | "+valeur;
  print += "\r\n";
  return print;
}

std::string ExpressionConstante::toSmallString() {
  return "CONST"+valeur;
}
