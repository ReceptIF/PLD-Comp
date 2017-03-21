#ifndef PLD_COMP_EXPRESSIONUNAIRE_H
#define PLD_COMP_EXPRESSIONUNAIRE_H

#include "Expression.h"

class Expression;
class ExpressionUnaire : public Expression {

public:
    ExpressionUnaire();
    ~ExpressionUnaire();
    void setExpression1(Expression* &expression);
    void setSymbole(int &symbole);
    void setPrefixe(int &prefixe);
    Expression *getExpression1();
    int getSymbole();
    int getPrefixe();

private:
	Expression* expression1;
	int symbole;
	int prefixe;
};

#endif //PLD_COMP_EXPRESSIONUNAIRE_H
