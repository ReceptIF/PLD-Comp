#ifndef PLD_COMP_EXPRESSIONCONSTANTE_H
#define PLD_COMP_EXPRESSIONCONSTANTE_H

#include "Expression.h"

class Expression;
class ExpressionConstante : public Expression {

public:
    ExpressionConstante(int aType, int aValeur);
    ~ExpressionConstante();
    void typage();

private:
    int valeur;
};

#endif //PLD_COMP_EXPRESSIONCONSTANTE_H
