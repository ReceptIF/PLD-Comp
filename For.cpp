#include "For.h"

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
