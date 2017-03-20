#ifndef PLD_COMP_EXPRESSIONVARIABLE_H
#define PLD_COMP_EXPRESSIONVARIABLE_H

#include "Expression.h"
#include "Variable.h"

class ExpressionVariable : public Expression {

public:
    ExpressionVariable();
    ~ExpressionVariable();

private:
	Variable* variable;
};

#endif //PLD_COMP_EXPRESSIONVARIABLE_H
