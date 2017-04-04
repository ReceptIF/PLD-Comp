#ifndef PLD_COMP_FOR_H
#define PLD_COMP_FOR_H

#include "Structure.h"
#include "Bloc.h"
#include "Expression.h"

class BasicBlock;
class For : public Structure {

public:
    For(Expression* init, Expression* cond, Expression* ite, Bloc* bloc);
    For(Expression* init, Expression* cond, Expression* ite, Instruction* instru);
    ~For();

    void SetBloc(Bloc* bloc);

    void SetInitialisation(Expression* expression);

    void SetCondition(Expression* expression);

    void SetIteration(Expression* expression);

    Bloc* GetBloc();

    Expression* GetInitialisation();

    Expression* GetCondition();

    Expression* GetIteration();
    
    std::string toString();
    
    void getIR(BasicBlock *bb, list<Instruction *> endInstr);

private:
    Bloc* bloc;
    Expression* initialisation;
    Expression* condition;
    Expression* iteration;

};

#endif //PLD_COMP_FOR_H
