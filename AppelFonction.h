#ifndef PLD_COMP_APPELFONCTION_H
#define PLD_COMP_APPELFONCTION_H

#include <string>
#include <list>

#include "Expression.h"

class Expression;
class AppelFonction : public Expression {

public:
    AppelFonction(std::string nomFonction);
    ~AppelFonction();
    std::string toString();
    std::string toSmallString();
    void setParametres(std::list<Expression *> *list);
    void typage();

private:
	std::string nomFonction;
  std::list<Expression *> parametres;

};

#endif //PLD_COMP_APPELFONCTION_H
