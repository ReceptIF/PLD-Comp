#ifndef PLD_COMP_CFG_H
#define PLD_COMP_CFG_H

#include "Programme.h"
#include <map>
#include <list>

class CFG {

public:
    CFG();
    ~CFG();
    void genererAssembleur();

private:
    std::map <std::string,Declaration *> variableMap;
    std::map <std::string,Fonction *> fonctionMap;
    std::list<BasicBlock*> basicBlocks;
    Programme *ast;

};

#endif //PLD_COMP_CFG_H
