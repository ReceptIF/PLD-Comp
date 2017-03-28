#include "CFG.h"
using namespace std;

CFG::CFG(Fonction *fct, IR *ir)
{
  
  ast = fct;
  this->ir = ir;
  
}

CFG::~CFG()
{

}

void CFG::addBB(BasicBlock *bb) {
  this->basicBlocks.push_back(bb);
}

std::string CFG::genererAssembleur() {
  
  std::string ass;
  ass += this->ast->getNom()+":\r\n";
  ass += "\r\n";
  ass += "    retq\r\n";
  ass += "\r\n";
  
  return ass;
  
}
