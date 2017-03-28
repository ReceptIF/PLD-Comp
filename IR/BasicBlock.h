#ifndef PLD_COMP_BASICBLOCK_H
#define PLD_COMP_BASICBLOCK_H

#include "IRInstr.h"
#include "../Fonction.h"
#include "IRVar.h"
#include <list>
#include <string>

class CFG;
class BasicBlock {

    public:
        BasicBlock();
        BasicBlock(Bloc *blc, CFG *cfg, std::string aLabel);
        ~BasicBlock();

        std::string genererAssembleur();

    private:
        std::list<IRInstr*> irInstrList;
        std::string label;
        BasicBlock* inCondSucc;
        BasicBlock* condSucc;
        CFG* cfg;

};

#endif //PLD_COMP_BASICBLOCK_H
