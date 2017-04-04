#include "StructCond.h"
#include "IR/BasicBlock.h"
#include "IR/CFG.h"

using namespace std;

StructCond::StructCond()
{
    blocElse = nullptr;
}

StructCond::StructCond(Clause* clause)
{
    AjouteClause(clause);
}

StructCond::StructCond(Instruction* instruction)
{
    Bloc *b = new Bloc();
    b->AjouteInstruction(instruction);
    this->blocElse = b;
}

StructCond::~StructCond()
{

}

void StructCond::AjouteClause(Clause* clause)
{
    clauses.push_back(clause);
}

std::list<Clause *> StructCond::GetClauses() {
    return clauses;
}

Bloc *StructCond::getElse() {
    return this->blocElse;
}

std::string StructCond::toString() {
  std::string print;
  print += "[S] === Début de la structure IF/ELSE ===\r\n";
 
  std::list<Clause *>::iterator i = this->clauses.begin() ;
  while ( i != this->clauses.end() ) {
    print += "[S] = Début de la clause ("+(*i)->getExpression()->toSmallString()+")\r\n";
    print += (*i)->getBloc()->toString();
    print += "[S] = Fin de la clause\r\n";
    i++;
  }
  
  if(blocElse != nullptr) {
    print += "[S] = Début de la clause ELSE\r\n";
    print += this->blocElse->toString();
    print += "[S] = Fin de la clause\r\n";
  }
 
  print += "[S] === Fin de la structure IF/ELSE ===\r\n";
  return print;
}

void StructCond::getIR(BasicBlock *bb, list<Instruction *> endInstr) {
  
  std::list<Clause *>::iterator i = this->clauses.begin() ;
  IRVar *condition = (*i)->getExpression()->getIR(bb);
  
  BasicBlock *bbIn = new BasicBlock((*i)->getBloc()->getInstructions(), bb->getCFG());
  BasicBlock *bbEnd = new BasicBlock(endInstr, bb->getCFG());;
  
  bb->setOutCond(condition);
  bb->setJumpCond(bbIn);
  
  bb->getCFG()->addBB(bbIn);
  
  if(this->blocElse != nullptr) {
    
    BasicBlock *bbNot = new BasicBlock(this->getElse()->getInstructions(), bb->getCFG());
    bb->setJumpIncond(bbNot);
    bbNot->setJumpIncond(bbEnd);
    bbIn->setJumpIncond(bbEnd);
    
    bb->getCFG()->addBB(bbNot);
    
  } else {
    
    bb->setJumpIncond(bbEnd);
    bbIn->setJumpIncond(bbEnd);
    
  }
  
  bb->getCFG()->addBB(bbEnd);
    
}
