#ifndef PLD_COMP_VARIABLE_H
#define PLD_COMP_VARIABLE_H

#include "Type.h"

class Variable {

public:
	Variable();
    ~Variable();

private:
    Type type;
    String nom;

};

#endif //PLD_COMP_VARIABLE_H
