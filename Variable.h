#ifndef PLD_COMP_VARIABLE_H
#define PLD_COMP_VARIABLE_H

#include <iostream>
#include <string>

class Variable {

public:
	Variable(std::string nomVar);
  ~Variable();
  std::string getNom();

private:
    std::string nomVariable;
};

#endif //PLD_COMP_VARIABLE_H
