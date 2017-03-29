#ifndef PLD_COMP_EXPRESSION_H
#define PLD_COMP_EXPRESSION_H

#include "Instruction.h"
#include "Declaration.h"
#include <string>
#include <map>
#include <list>
#include "IR/IRVar.h"

class Instruction;
class BasicBlock;
class Expression : public Instruction {

public:
    Expression();
    ~Expression();
    virtual void typage()=0;
    virtual std::string toString() =0;
    virtual std::string toSmallString() =0;
    int getType();
    std::string stringifySymbole(int symb);
    
    virtual void resoudrePortees(std::list<std::string> *varStack, std::map<std::string,Declaration *> *varMap, std::list<std::string> *fctStack) = 0;
    virtual IRVar *getIR(BasicBlock *bb) =0;

protected:
    int type;

private:

};

#endif //PLD_COMP_EXPRESSION_H
