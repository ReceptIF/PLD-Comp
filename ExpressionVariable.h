#ifndef PLD_COMP_EXPRESSIONVARIABLE_H
#define PLD_COMP_EXPRESSIONVARIABLE_H

#include "Expression.h"
#include "Variable.h"
#include "VariableSimple.h"
#include "VariableTableau.h"
#include <string>

class Expression;
class ExpressionVariable : public Expression {

public:
    ExpressionVariable(std::string nomVariable);
    ExpressionVariable(std::string nomVariable, Expression *e);
    ~ExpressionVariable();
    void typage();
    
    std::string toString();
    std::string toSmallString();

private:
	Variable* variable;
};

#endif //PLD_COMP_EXPRESSIONVARIABLE_H
