#ifndef PLD_COMP_VARIABLESIMPLE_H
#define PLD_COMP_VARIABLESIMPLE_H

#include "Variable.h"

class Variable;
class VariableSimple : public Variable {

public:
	VariableSimple(std::string nomVar):Variable(nomVar) {};
  ~VariableSimple();
  std::string toSmallString();

private:

};

#endif //PLD_COMP_VARIABLESIMPLE_H
