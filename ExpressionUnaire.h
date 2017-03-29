#ifndef PLD_COMP_EXPRESSIONUNAIRE_H
#define PLD_COMP_EXPRESSIONUNAIRE_H

#include "Expression.h"

class Expression;
class ExpressionUnaire : public Expression {

public:
    ExpressionUnaire(Expression *e, int symb, int pref);
    ~ExpressionUnaire();
    void setExpression1(Expression* expression);
    void setSymbole(int symbole);
    void setPrefixe(int prefixe);
    Expression *getExpression1();
    int getSymbole();
    int getPrefixe();
    void typage();
    
    std::string toString();
    std::string toSmallString();
    
  void resoudrePortees(std::list<std::string> *varStack, std::map<std::string,Declaration *> *varMap, std::list<std::string> *fctStack);
  IRVar *getIR(BasicBlock *bb);

private:
	Expression* expression1;
	int symbole;
	int prefixe;
};

#endif //PLD_COMP_EXPRESSIONUNAIRE_H
