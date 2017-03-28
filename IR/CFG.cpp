#include "CFG.h"
using namespace std;

CFG::CFG()
{

}

CFG::~CFG()
{

}

void CFG::addBB(BasicBlock *bb) {
  this->basicBlocks.push_back(bb);
}

std::string CFG::genererAssembleur() {
  
  std::string ass;
  ass += ".text                       # section declaration\r\n";
  ass += ".global main                # entry point\r\n";
  ass += "\r\n";
  
  std::list<BasicBlock*>::iterator ite;
  for(ite=basicBlocks.begin();ite!=basicBlocks.end();ite++) {
      
      ass += (*ite)->genererAssembleur();
      
  }
  
  return ass;
  
}

void CFG::mettreEnPlaceIR(Programme *prog) {
  
  ast = prog;
  variableMap = ast->getVariables();
  fonctionMap = ast->getFonctions();
  
  // Generation des BB de fonctions
  map<std::string,Fonction *>::iterator fct;
  
  for(fct = fonctionMap.begin() ; fct!=fonctionMap.end() ; fct++)
  {
      BasicBlock *bf = new BasicBlock(fct->second);
      this->addBB(bf);
  }
  
}
