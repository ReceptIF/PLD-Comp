#ifndef PLD_COMP_DECLARATION_H
#define PLD_COMP_DECLARATION_H

#include "Instruction.h"
#include <string>

class Declaration : public Instruction {

public:
    Declaration();
    ~Declaration();

private:
    string nomVariable;
    int type;

};

#endif //PLD_COMP_DECLARATION_H
