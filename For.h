#ifndef PLD_COMP_FOR_H
#define PLD_COMP_FOR_H

#include "Structure.h"
#include "Bloc.h"
#include "Expression.h"

class For : public Structure {

public:
    For();
    For(Expression* init, Expression* cond, Expression* ite, Bloc* bloc);
    For(Expression* init, Expression* cond, Expression* ite, Instruction* instru);
    ~For();

    void SetBloc(Bloc* bloc);

    void SetInstruction(Instruction* instru);

    void SetInitialisation(Expression* expression);

    void SetCondition(Expression* expression);

    void SetIteration(Expression* expression);

    Bloc* GetBloc();

    Instruction* GetInstruction();

    Expression* GetInitialisation();

    Expression* GetCondition();

    Expression* GetIteration();

private:
    Bloc* bloc;
    Instruction* instruction;
    Expression* initialisation;
    Expression* condition;
    Expression* iteration;

};

#endif //PLD_COMP_FOR_H
