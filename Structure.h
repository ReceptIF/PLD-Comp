#ifndef PLD_COMP_STRUCTURE_H
#define PLD_COMP_STRUCTURE_H

#include "Instruction.h"

class Instruction;
class Structure : public Instruction {

public:
	Structure();
	~Structure();
  virtual std::string toString() = 0;

private:

};

#endif //PLD_COMP_STRUCTURE_H
