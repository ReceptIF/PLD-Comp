#ifndef PLD_COMP_APPELFONCTION_H
#define PLD_COMP_APPELFONCTION_H

#include <string>

#include "Expression.h"

class Expression;
class AppelFonction : public Expression {

public:
    AppelFonction();
    ~AppelFonction();

private:
	string nomFonction

};

#endif //PLD_COMP_APPELFONCTION_H
