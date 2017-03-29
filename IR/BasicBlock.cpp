#include "BasicBlock.h"
#include "CFG.h"
#include "../AppelFonction.h"
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
        
      } else if (dynamic_cast<AppelFonction *>(*i)) {
        
        AppelFonction *a = (AppelFonction *)*i;
        a->getIR(this);
        
      }
      
      i++;
    }
  
}

BasicBlock::~BasicBlock()
{

}

std::string BasicBlock::genererAssembleur() {
    std::string ass;
    
    std::list<IRInstr *>::iterator i = irInstrList.begin();
    while(i != irInstrList.end()) {
      ass += (*i)->genererAssembleur();
      i++;
    }
  
    return ass;
}

CFG *BasicBlock::getCFG() {
    return cfg;
}

void BasicBlock::addInstr(IRInstr *i) {
    irInstrList.push_back(i);
}
