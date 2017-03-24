#ifndef PLD_COMP_CLAUSE_H
#define PLD_COMP_CLAUSE_H

#include "Instruction.h"
#include "Expression.h"
#include "Bloc.h"

class Clause {

public:
    Clause(Expression *condition, Bloc *instructions):expression(condition),bloc(instructions) {};
    Clause(Expression *condition, Instruction *instruction);
    ~Clause();
    Expression *getExpression();
    Bloc *getBloc();

private:
	Expression *expression;
  Bloc *bloc;
};

#endif //PLD_COMP_CLAUSE_H
