#include "While.h"
#include "IR/BasicBlock.h"
#include "IR/CFG.h"

While::While(Expression *expression, Bloc *bloc) {
  
  Clause *c = new Clause(expression,bloc);
  clause = c;
  
}

While::While(Expression *expression, Instruction *instruction) {
  
  Bloc *bloc = new Bloc();
  bloc->AjouteInstruction(instruction);
  
  Clause *c = new Clause(expression,bloc);
  clause = c;
  
}

While::~While() {
  delete clause;
}

Clause *While::getClause() {
  return clause;
}

std::string While::toString() {
  std::string print;
  print += "[S] === Début de la structure WHILE ===\r\n";
  print += "[S] Cond : "+clause->getExpression()->toSmallString()+"\r\n";
  print += clause->getBloc()->toString();
  print += "[S] === Fin de la structure WHILE ===\r\n";
  return print;
}

void While::getIR(BasicBlock *bb, list<Instruction *> endInstr) {
  
  IRVar *condition = this->clause->getExpression()->getIR(bb);
  BasicBlock *bbIn = new BasicBlock(this->clause->getBloc()->getInstructions(), bb->getCFG());
  IRVar *conditionBis = this->clause->getExpression()->getIR(bbIn);
  BasicBlock *bbEnd = new BasicBlock(endInstr, bb->getCFG());;
  
  bb->setOutCond(condition);
  bb->setJumpCond(bbIn);
  bb->setJumpIncond(bbEnd);
  
  bbIn->setOutCond(conditionBis);
  bbIn->setJumpCond(bbIn);
  bbIn->setJumpIncond(bbEnd);
  
  bb->getCFG()->addBB(bbIn);
  bb->getCFG()->addBB(bbEnd);
    
}
