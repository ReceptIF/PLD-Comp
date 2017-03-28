#include "IR.h"
using namespace std;

IR::IR(Programme *prog)
{
  
  map<std::string,Fonction *>::iterator fct;
  
  for(fct = prog->getFonctions().begin() ; fct != prog->getFonctions().end() ; fct++)
  {
      CFG *bf = new CFG(fct->second,this);
      this->addCFG(bf);
  }
  
}

IR::~IR()
{

}

void IR::addCFG(CFG *cfg) {
  this->cfgs.push_back(cfg);
}

std::string IR::genererAssembleur() {
  
  std::string ass;
  ass += ".text                       # section declaration\r\n";
  ass += ".global main                # entry point\r\n";
  ass += "\r\n";
  
  std::list<CFG*>::iterator ite;
  for(ite=cfgs.begin();ite!=cfgs.end();ite++) {
      
      ass += (*ite)->genererAssembleur();
      
  }
  
  return ass;
}
