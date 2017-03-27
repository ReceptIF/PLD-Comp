#ifndef PLD_COMP_EXPRESSIONCONSTANTE_H
#define PLD_COMP_EXPRESSIONCONSTANTE_H

#include "Expression.h"
#include <iostream>

class Expression;
class ExpressionConstante : public Expression {

public:
    ExpressionConstante(int aType, int aValeur);
    ~ExpressionConstante();
    void typage();
    
    std::string toString();
    std::string toSmallString();
    
    void resoudrePortees(std::list<std::string> *varStack, std::map<std::string,Declaration *> *varMap, std::list<std::string> *fctStack) {};

private:
    int valeur;
};

#endif //PLD_COMP_EXPRESSIONCONSTANTE_H
