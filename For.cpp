#include "For.h"

For::For()
{
    this->bloc = nullptr;
    condition = nullptr;
    initialisation = nullptr;
    iteration = nullptr;
}

For::For(Expression* init, Expression* cond, Expression* ite, Bloc* bloc)
{
    this->bloc = bloc;
    condition = cond;
    initialisation = init;
    iteration = ite;
}

For::For(Expression* init, Expression* cond, Expression* ite, Instruction* instru)
{
    instruction = instru;
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
  return "[I] For";
}
