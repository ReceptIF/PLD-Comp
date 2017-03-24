#include "For.h"

For::For(Expression* init, Expression* cond, Expression* ite, Bloc* blocos)
{
    bloc = blocos;
    instruction = nullptr;
    condition = cond;
    initialisation = init;
    iteration = ite;
}

For::For(Expression* init, Expression* cond, Expression* ite, Instruction* instru)
{
    bloc = nullptr;
    instruction = instru;
    condition = cond;
    initialisation = init;
    iteration = ite;
}

For::~For()
{
    delete bloc;
    delete instruction;
    delete condition;
    delete initialisation;
    delete iteration;
}

void For::SetBloc(Bloc* bloc)
{
    bloc = bloc;
}

void For::SetInstruction(Instruction* instru)
{
    instruction = instru;
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

Instruction* For::GetInstruction()
{
    return instruction;
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

std::string For::toString() {
  std::string print;
  
  print += "[S] === Début de la structure FOR === \r\n";
  print += "[S] Init : "+initialisation->toSmallString()+"\r\n";
  print += "[S] Cond : "+condition->toSmallString()+"\r\n";
  print += "[S] Iter : "+iteration->toSmallString()+"\r\n";
  
  if(bloc != nullptr) 
  {
    print += bloc->toString();
  }
  else if(instruction != nullptr) 
  {
    print += instruction->toString();
  }
  
  print += "[S] === Fin de la structure FOR ===\r\n";
  return print;
}
