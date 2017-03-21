#ifndef PLD_COMP_VARIABLETABLEAU_H
#define PLD_COMP_VARIABLETABLEAU_H

#include "Variable.h"
#include "Expression.h"

class Variable;
class VariableTableau : public Variable {

public:
	VariableTableau();
    ~VariableTableau();

private:
	Expression* indice;
};

#endif //PLD_COMP_VARIABLETABLEAU_H
