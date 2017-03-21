#ifndef PLD_COMP_DECLARATION_H
#define PLD_COMP_DECLARATION_H

#include "Instruction.h"
#include <iostream>
#include <string>

class Instruction;
class Declaration : public Instruction {

public:
    Declaration();
    ~Declaration();

private:
    std::string nomVariable;
    int type;

};

#endif //PLD_COMP_DECLARATION_H
