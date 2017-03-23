#ifndef PLD_COMP_APPELFONCTION_H
#define PLD_COMP_APPELFONCTION_H

#include <string>

#include "Expression.h"

class Expression;
class AppelFonction : public Expression {

public:
    AppelFonction(std::string nomFonction);
    ~AppelFonction();
    std::string toString();

private:
	std::string nomFonction;

};

#endif //PLD_COMP_APPELFONCTION_H
