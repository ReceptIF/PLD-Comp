#ifndef PLD_COMP_EXPRESSION_H
#define PLD_COMP_EXPRESSION_H

#include "Instruction.h"
#include <string>

class Instruction;
class Expression : public Instruction {

public:
    Expression();
    ~Expression();
    virtual void typage()=0;
    virtual std::string toString() =0;
    int getType();
    
protected:
    int type;

private:

};

#endif //PLD_COMP_EXPRESSION_H
