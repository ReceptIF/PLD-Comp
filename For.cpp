#include "For.h"
#include "IR/BasicBlock.h"
#include "IR/CFG.h"

For::For(Expression* init, Expression* cond, Expression* ite, Bloc* blocos)
{
    bloc = blocos;
    condition = cond;
    initialisation = init;
    iteration = ite;
}

For::For(Expression* init, Expression* cond, Expression* ite, Instruction* instru)
{
    Bloc *b = new Bloc();
    b->AjouteInstruction(instru);
  
    bloc = b;
    condition = cond;
    initialisation = init;
    iteration = ite;
}

For::~For()
{
    delete bloc;
    delete condition;
    delete initialisation;
    delete iteration;
}

void For::SetBloc(Bloc* bloc)
{
    bloc = bloc;
}

void For::SetCondition(Expression*  expression)
{
    condition = expression;
}

void For::SetInitialisation(Expression* expression)
{
    initialisation = expression;
}

void For::SetIteration(Expression* expression)
{
    iteration = expression;
}

Bloc* For::GetBloc()
{
    return bloc;
}

Expression* For::GetCondition()
{
    return condition;
}

Expression* For::GetInitialisation()
{
    return initialisation;
}

Expression* For::GetIteration()
{
    return iteration;
}

void For::getIR(BasicBlock *bb, list<Instruction *> endInstr) {
  
  // Initialisation
  this->initialisation->getIR(bb);
  
  // Test conditionnel
  IRVar *condition = this->condition->getIR(bb);
  BasicBlock *bbIn = new BasicBlock(this->bloc->getInstructions(), bb->getCFG());
  this->iteration->getIR(bbIn);
  IRVar *conditionBis = this->condition->getIR(bbIn);
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

std::string For::toString() {
  std::string print;
  
  print += "[S] === Début de la structure FOR === \r\n";
  print += "[S] Init : "+initialisation->toSmallString()+"\r\n";
  print += "[S] Cond : "+condition->toSmallString()+"\r\n";
  print += "[S] Iter : "+iteration->toSmallString()+"\r\n";
  print += bloc->toString();
  print += "[S] === Fin de la structure FOR ===\r\n";
  return print;
}
