#ifndef PLD_COMP_DECLARATION_H
#define PLD_COMP_DECLARATION_H

#include "Instruction.h"
#include "Expression.h"
#include <iostream>
#include <string>

class Instruction;
class Declaration : public Instruction {

public:
    Declaration(std::string nomVar, int varType, int size = -1);
    ~Declaration();

    void setNomVariable(std::string nV);
    std::string getNomVariable();

    void setType(int t);
    int getType();
    void setInit(Expression *e);
    
    std::string stringifyType();
    std::string toSmallString();
    std::string toString();

private:
    std::string nomVariable;
    int type;
    int tabSize;
    Expression *init;
};

#endif //PLD_COMP_DECLARATION_H
