#ifndef PLD_COMP_BASICBLOCK_H
#define PLD_COMP_BASICBLOCK_H

#include <list>
#include <string>

class BasicBlock {

    public:
        BasicBlock();
        BasicBlock(Fonction *fct);
        ~BasicBlock();

        void genererAssembleur();

    private:
        std::list<IRInstr*> irInstrList;
        std::string label;
        BasicBlock* inCondSucc;
        BasicBlock* condSucc;
        CFG* cfg;

};

#endif //PLD_COMP_BASICBLOCK_H
