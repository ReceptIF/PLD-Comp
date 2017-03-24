#ifndef PLD_COMP_RETURN_H
#define PLD_COMP_RETURN_H

#include "Instruction.h"
#include "Expression.h"
#include <iostream>
#include <string>

class Instruction;
class Return : public Instruction {

public:
    Return(Expression *e):expression(e) {};
    ~Return();
    std::string toString();

private:
    Expression *expression;

};

#endif //PLD_COMP_BREAK_H
