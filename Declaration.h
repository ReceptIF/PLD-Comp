#ifndef PLD_COMP_DECLARATION_H
#define PLD_COMP_DECLARATION_H

#include "Instruction.h"
#include <iostream>
#include <string>

class Instruction;
class Declaration : public Instruction {

public:
    Declaration();
    Declaration(std::string nomVar, int varType);
    ~Declaration();

    void setNomVariable(std::string nV);
    std::string getNomVariable();

    void setType(int t);
    int getType();
    
    std::string stringifyType();
    std::string toSmallString();

private:
    std::string nomVariable;
    int type;

};

#endif //PLD_COMP_DECLARATION_H
