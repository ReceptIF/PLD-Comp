#ifndef PLD_COMP_BREAK_H
#define PLD_COMP_BREAK_H

#include "Instruction.h"
#include <iostream>
#include <string>

class Instruction;
class Break : public Instruction {

public:
    Break();
    ~Break();
    std::string toString();

private:

};

#endif //PLD_COMP_BREAK_H
