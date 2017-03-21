#ifndef PLD_COMP_CLAUSE_H
#define PLD_COMP_CLAUSE_H

#include "Instruction.h"
#include "Expression.h"

class Instruction;
class Clause : public Instruction {

public:
    Clause();
    ~Clause();

private:
	Expression* expression;
};

#endif //PLD_COMP_CLAUSE_H
