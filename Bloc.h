#ifndef PLD_COMP_BLOC_H
#define PLD_COMP_BLOC_H

#include <list>
#include <iostream>
#include <string>
#include "Instruction.h"

class Bloc {

public:
    Bloc();
    ~Bloc();
    void AjouteInstruction(Instruction* instruction);
    std::string toString();

private:
    std::list <Instruction*> instructions;

};

#endif //PLD_COMP_BLOC_H
