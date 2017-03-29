#ifndef PLD_COMP_APPELFONCTION_H
#define PLD_COMP_APPELFONCTION_H

#include <string>
#include <list>
#include <map>

#include "Expression.h"
#include "Declaration.h"
#include "Fonction.h"
#include "IR/IRVar.h"
#include "IR/IRInstr.h"

class Expression;
class AppelFonction : public Expression {

public:
    AppelFonction(std::string nomFonction);
    ~AppelFonction();
    std::string toString();
    std::string toSmallString();
    void setParametres(std::list<Expression *> *list);
    void typage();
    void resoudrePortees(std::list<std::string> *varStack, std::map<std::string,Declaration *> *varMap, std::list<std::string> *fctStack);
    IRVar *getIR(BasicBlock *bb);
    
private:
	std::string nomFonction;
  std::list<Expression *> parametres;

};

#endif //PLD_COMP_APPELFONCTION_H
