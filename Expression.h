#ifndef PLD_COMP_EXPRESSION_H
#define PLD_COMP_EXPRESSION_H

#include "Instruction.h"

class Instruction;
class Expression : public Instruction {

public:
    Expression();
    ~Expression();
    virtual void typage();
    int getType();
    
protected:
    int type;

private:

};

#endif //PLD_COMP_EXPRESSION_H
