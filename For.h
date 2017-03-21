#ifndef PLD_COMP_FOR_H
#define PLD_COMP_FOR_H

#include "Structure.h"
#include "Bloc.h"
#include "Expression.h"

class For : public Structure {

public:
    For();

    ~For();

    void SetBloc(Bloc* & bloc);

    void SetInitialisation(Expression* &expression);

    void SetCondition(Expression* &expression);

    void SetIteration(Expression* &expression);

    Bloc GetBloc();

    Expression GetInitialisation();

    Expression GetCondition();

    Expression GetIteration();

private:
    Bloc* bloc;
    Expression* initialisation;
    Expression* condition;
    Expression* iteration;

};

#endif //PLD_COMP_FOR_H
