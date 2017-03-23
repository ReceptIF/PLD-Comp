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
    virtual std::string toSmallString() =0;
    int getType();
    std::string stringifySymbole(int symb);
    
protected:
    int type;

private:

};

#endif //PLD_COMP_EXPRESSION_H
