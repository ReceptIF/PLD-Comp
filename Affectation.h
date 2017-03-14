#ifndef PLD_COMP_AFFECTATION_H
#define PLD_COMP_AFFECTATION_H

#include "Instruction.h"
#include "Variable.h"
#include "Expression.h"

class Affectation : public Instruction {

public:
    Affectation();
    ~Affectation();

private:
    Variable variable;
    Expression expression;
};

#endif //PLD_COMP_AFFECTATION_H
