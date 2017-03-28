#include "CFG.h"
using namespace std;

CFG::CFG()
{

}

CFG::~CFG()
{

}

std::string genererAssembleur() {
  
  std::string ass;
  ass += ".text                       # section declaration\r\n";
  ass += ".global main                # section declaration\r\n";
  ass += "\r\n";
  
  std::list<BasicBlock*>::iterator ite;
  for(ite=basicBlocks.begin();ite!=basicBlocks.end();ite++) {
      
      ass += (*ite)->genererAssembleur();
      
  }
  
}

void mettreEnPlaceIR(Programme *prog) {
  
  ast = prog;
  variableMap = ast->getVariables();
  fonctionMap = ast->getFonctions();
  
  // Generation des BB de fonctions
  
  for(fonctionMap::iterator fct=fonctionMap.begin() ; fct!=fonctionMap.end() ; ++fct)
  {
      BasicBlock *bf = new BasicBlock(fct->second);
  }
  
}
