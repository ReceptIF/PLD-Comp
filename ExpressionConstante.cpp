#include "ExpressionConstante.h"
#include "IR/BasicBlock.h"
#include "IR/CFG.h"

ExpressionConstante::ExpressionConstante(int aType, int aValeur)
{
  this->type = aType;
  this->valeur = aValeur;
  std::cout << "Création Const " << this->toSmallString() << std::endl;
}

ExpressionConstante::~ExpressionConstante()
{

}

void ExpressionConstante::typage() {
  // doNothing
}

std::string ExpressionConstante::toString() {
  std::string print = "[I] ExprConst | ";
  print += std::to_string(this->valeur);
  print += "\r\n";
  return print;
}

std::string ExpressionConstante::toSmallString() {
  
  std::string print;
  
  switch(this->type) {
    case INT32: print=std::to_string(valeur); break;
    case INT64: print=std::to_string(valeur); break;
    case CHAR:  print=valeur; break;
  }
  return print;
}

int ExpressionConstante::getValeur() {
  return valeur;
}

IRVar *ExpressionConstante::getIR(BasicBlock *bb) {
  
  int tmpVar = bb->getCFG()->addTempVar(this->type);
  IRVar *ret = bb->getCFG()->getVariable("!r"+to_string(tmpVar));
  
  list<std::string> params;
  params.push_back("@!r"+to_string(tmpVar));
  params.push_back("$"+to_string(this->valeur));
  IRInstr *instr = new IRInstr(bb->getCFG(),MNEMO_CONST,params);
  bb->addInstr(instr);
  
  return ret;
}
