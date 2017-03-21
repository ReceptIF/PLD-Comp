#ifndef PLD_COMP_EXPRESSION_H
#define PLD_COMP_EXPRESSION_H

#include "Instruction.h"

class Instruction;
class Expression : public Instruction {

public:
    Expression();
    ~Expression();
    
protected:
    int type;

private:

};

#endif //PLD_COMP_EXPRESSION_H
