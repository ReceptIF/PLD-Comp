#ifndef PLD_COMP_EXPRESSIONBINAIRE_H
#define PLD_COMP_EXPRESSIONBINAIRE_H

#include "Expression.h"

class Expression;
class BasicBlock;
class ExpressionBinaire : public Expression {

public:
    ExpressionBinaire(Expression *e1, Expression *e2, int symb);
    ~ExpressionBinaire();
    void setExpression1(Expression* expression);
    void setExpression2(Expression* expression);
    void setSymbole(int &symbole);
    Expression *getExpression1();
    Expression *getExpression2();
    int getSymbole();
    
    std::string toString();
    std::string toSmallString();
    
    void typage();
    void resoudrePortees(std::list<std::string> *varStack, std::map<std::string,Declaration *> *varMap, std::list<std::string> *fctStack);
    void getIR(BasicBlock *bb);

private:
	Expression* expression1;
	Expression* expression2;
	int symbole;

};

#endif //PLD_COMP_EXPRESSIONBINAIRE_H
