#ifndef PLD_COMP_CFG_H
#define PLD_COMP_CFG_H

#include "../Programme.h"
#include "../Fonction.h"
#include "../Enum.h"
#include "BasicBlock.h"
#include "IRVar.h"
#include <map>
#include <list>
#include <string>

class IR;
class CFG {

public:
    CFG(Fonction *fonction, IR *ir);
    ~CFG();
    std::string genererAssembleur();
    void addBB(BasicBlock *bb, int rank = -1);
    void addVariable(IRVar var);
    int addTempVar(int type);
    int giveOffsets();
    IRVar *getVariable(std::string name);
    int *getNbBloc();
    Fonction *getAST();

private:
    std::map <std::string,IRVar> variableMap;
    std::list<BasicBlock*> basicBlocks;
    Fonction *ast;
    IR *ir;
    int nbTemp;
    int nbBloc;

};

#endif //PLD_COMP_CFG_H
