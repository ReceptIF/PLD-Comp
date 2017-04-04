#include "BasicBlock.h"
#include "CFG.h"
#include "../AppelFonction.h"
#include "../StructCond.h"
#include "../While.h"
#include "../Return.h"
using namespace std;

BasicBlock::BasicBlock()
{
  
}

BasicBlock::BasicBlock(list<Instruction *> instructions, CFG *cfg, std::string aLabel) {
  
    this->cfg = cfg;
    this->jumpCond = nullptr;
    this->jumpIncond = nullptr;
    this->outCond = nullptr;
    
    int *nbBloc = cfg->getNbBloc();
    this->bbId = (*nbBloc)++;
    
    this->label = cfg->getAST()->getNom()+".bloc"+to_string(this->bbId);
    
    std::list<Instruction *>::iterator i = instructions.begin();
    while(i != instructions.end()) {
      
      if (dynamic_cast<Declaration *>(*i)) {
        
        Declaration *d = (Declaration *)*i;
        IRVar var(d->getType(), d->getNomVariable(), 0);
        if(d->getTabSize() > 0) { var.setSize(d->getTabSize()); }
        cfg->addVariable(var);
        
      } else if (dynamic_cast<AppelFonction *>(*i)) {
        
        AppelFonction *a = (AppelFonction *)*i;
        a->getIR(this);
        
      } else if (dynamic_cast<ExpressionBinaire *>(*i)) {
        
        ExpressionBinaire *e = (ExpressionBinaire *)*i;
        e->typage();
        e->getIR(this);
        
      } else if (dynamic_cast<ExpressionUnaire *>(*i)) {
        
        ExpressionUnaire *e = (ExpressionUnaire *)*i;
        e->typage();
        e->getIR(this);
        
      }else if (dynamic_cast<ExpressionConstante *>(*i)) {
        
        ExpressionConstante *e = (ExpressionConstante *)*i;
        e->typage();
        e->getIR(this);
        
      }else if (dynamic_cast<StructCond *>(*i)) {
        
        StructCond *s = (StructCond *)*i;
        
        int itePos = std::distance(instructions.begin(), i)+1;
        list<Instruction *> endInstr = this->CopyNotEntireList(instructions,itePos);
        
        s->getIR(this, endInstr);
        i = instructions.end();
        i--;
        
      }else if (dynamic_cast<While *>(*i)) {
        
        While *s = (While *)*i;
        
        int itePos = std::distance(instructions.begin(), i)+1;
        list<Instruction *> endInstr = this->CopyNotEntireList(instructions,itePos);
        
        s->getIR(this, endInstr);
        i = instructions.end();
        i--;
        
      }else if (dynamic_cast<Return *>(*i)) {
        
        Return *r = (Return *)*i;
        r->getIR(this);
        
      }
      
      i++;
    }
  
}

BasicBlock::~BasicBlock()
{
  
    delete jumpIncond;
    delete jumpCond;
    delete outCond;
    delete cfg;
    list<IRInstr*>::iterator it;
    for(it = irInstrList.begin(); it!=irInstrList.end(); ++it)
    {
        delete *it;
    }

}

std::string BasicBlock::genererAssembleur() {
    std::string ass;
    
    // Déroulement des instructions
    std::list<IRInstr *>::iterator i = irInstrList.begin();
    while(i != irInstrList.end()) {
      ass += (*i)->genererAssembleur();
      i++;
    }
    
    
    // Gestion des sauts
    
    if(jumpIncond != nullptr) {
      if(jumpCond != nullptr && outCond != nullptr) {
    
        int varOffset = outCond->getOffset();
        string p = to_string(varOffset)+"(%rbp)";
        
        ass += "    cmpq    $1, "+p+" \r\n";
        ass += "    je      "+jumpCond->getLabel()+" \r\n";
        ass += "    jmp     "+jumpIncond->getLabel()+" \r\n";
        
      } else {
        
        ass += "    jmp     "+jumpIncond->getLabel()+" \r\n";
        
      }
    }
  
    return ass;
}

CFG *BasicBlock::getCFG() {
    return cfg;
}

int BasicBlock::getId() {
  return this->bbId;
}

void BasicBlock::addInstr(IRInstr *i) {
    irInstrList.push_back(i);
}

void BasicBlock::setJumpCond(BasicBlock *bb) {
  jumpCond = bb;
}

void BasicBlock::setJumpIncond(BasicBlock *bb) {
  jumpIncond = bb;
}

void BasicBlock::setOutCond(IRVar *condition) {
  outCond = condition;
}

string BasicBlock::getLabel() {
  return label;
}

list<Instruction*> BasicBlock::CopyNotEntireList(list<Instruction*> &currentList, unsigned int beginAt, unsigned int size)
{
    list<Instruction*> newList;
    list<Instruction*>::iterator it=currentList.begin();
    unsigned int curPos = 0;

    while(it != currentList.end())
    {
        if(curPos >= beginAt && (curPos - beginAt < size || size == 0))
        {
            newList.push_back(*it);
        }

        curPos++;
        ++it;
    }

    return newList;
}
