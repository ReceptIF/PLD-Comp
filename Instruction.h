#ifndef PLD_COMP_INSTRUCTION_H
#define PLD_COMP_INSTRUCTION_H

#include "Enum.h"
#include <string>

class Instruction {

public:

	Instruction();
	~Instruction();
  virtual std::string toString() = 0;

protected:

private:

};

#endif //PLD_COMP_INSTRUCTION_H
