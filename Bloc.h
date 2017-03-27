#ifndef PLD_COMP_BLOC_H
#define PLD_COMP_BLOC_H

#include <list>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include "Instruction.h"
#include "Declaration.h"
#include "Expression.h"
#include "ExpressionBinaire.h"
#include "ExpressionUnaire.h"
#include "ExpressionVariable.h"
#include "ExpressionConstante.h"

class Bloc {

public:
    Bloc();
    ~Bloc();
    void AjouteInstruction(Instruction* instruction);
    std::string toString();
    
    void resoudrePortees(int *globalContext, std::list<std::string> *varStack, std::map<std::string,Declaration *> *varMap, std::list<std::string> *fctStack);

private:
    std::list <Instruction*> instructions;

};

#endif //PLD_COMP_BLOC_H
