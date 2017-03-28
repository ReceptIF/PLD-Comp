#ifndef PLD_COMP_CFG_H
#define PLD_COMP_CFG_H

#include "../Programme.h"
#include "../Fonction.h"
#include "BasicBlock.h"
#include <map>
#include <list>
#include <string>

class IR;
class CFG {

public:
    CFG(Fonction *fonction, IR *ir);
    ~CFG();
    std::string genererAssembleur();
    void addBB(BasicBlock *bb);

private:
    std::map <std::string,Declaration *> variableMap;
    std::list<BasicBlock*> basicBlocks;
    Fonction *ast;
    IR *ir;

};

#endif //PLD_COMP_CFG_H
