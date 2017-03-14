#include "For.h"

For::For()
{

}

For::~For()
{

}

void For::SetBloc(Bloc & bloc)
{
    bloc = bloc;
}

void For::SetCondition(Expression & expression)
{
    condition = expression;
}

void For::SetInitialisation(Expression & expression)
{
    initialisation = expression;
}

void For::SetIteration(Expression & expression)
{
    iteration = expression;
}

Bloc For::GetBloc()
{
    return bloc;
}

Expression For::GetCondition()
{
    return condition;
}

Expression For::GetInitialisation()
{
    return initialisation;
}

Expression For::GetIteration()
{
    return iteration;
}