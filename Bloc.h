#ifndef PLD_COMP_BLOC_H
#define PLD_COMP_BLOC_H

#include <list>
#include "Instruction.h"

class Bloc {

public:
    Bloc();
    ~Bloc();
    void AjouteInstruction(Instruction* instruction);

private:
    std::list <Instruction*> instructions;

};

#endif //PLD_COMP_BLOC_H
