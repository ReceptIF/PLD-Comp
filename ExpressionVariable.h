#ifndef PLD_COMP_EXPRESSIONVARIABLE_H
#define PLD_COMP_EXPRESSIONVARIABLE_H

#include "Expression.h"
#include "Variable.h"
#include <string>

class Expression;
class ExpressionVariable : public Expression {

public:
    ExpressionVariable(std::string nomVariable);
    ~ExpressionVariable();
    void typage();

private:
	Variable* variable;
};

#endif //PLD_COMP_EXPRESSIONVARIABLE_H
