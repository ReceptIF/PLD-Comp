#include "BasicBlock.h"
#include "CFG.h"
using namespace std;

BasicBlock::BasicBlock()
{

}

BasicBlock::BasicBlock(Bloc *blc, CFG *cfg, std::string aLabel) {
  
    this->cfg = cfg;
    this->label = aLabel;
    
    list<Instruction *> instructions = blc->getInstructions();
    std::list<Instruction *>::iterator i = instructions.begin();
    while(i != instructions.end()) {
      
      if (dynamic_cast<Declaration *>(*i)) {
        Declaration *d = (Declaration *)*i;
        IRVar var(d->getType(), d->getNomVariable(), 0);
        cfg->addVariable(var);
      }
      
      i++;
    }
  
}

BasicBlock::~BasicBlock()
{

}

std::string BasicBlock::genererAssembleur() {
  
  
  
}
