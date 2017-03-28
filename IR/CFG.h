#ifndef PLD_COMP_CFG_H
#define PLD_COMP_CFG_H

#include "../Programme.h"
#include "../Fonction.h"
#include "BasicBlock.h"
#include <map>
#include <list>
#include <string>

class CFG {

public:
    CFG();
    ~CFG();
    std::string genererAssembleur();
    void addBB(BasicBlock *bb);
    void mettreEnPlaceIR(Programme *prog);

private:
    std::map <std::string,Declaration *> variableMap;
    std::map <std::string,Fonction *> fonctionMap;
    std::list<BasicBlock*> basicBlocks;
    Programme *ast;

};

#endif //PLD_COMP_CFG_H
