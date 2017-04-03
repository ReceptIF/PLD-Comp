#ifndef PLD_COMP_BASICBLOCK_H
#define PLD_COMP_BASICBLOCK_H

#include "IRInstr.h"
#include "../Fonction.h"
#include "../Instruction.h"
#include "IRVar.h"
#include <list>
#include <string>

class CFG;
class BasicBlock {

    public:
        BasicBlock();
        BasicBlock(list<Instruction *> instructions, CFG *cfg, std::string aLabel = "unknown");
        ~BasicBlock();

        std::string genererAssembleur();
        CFG *getCFG();
        void addInstr(IRInstr *i);
        int getId();
        string getLabel();
        
        void setJumpCond(BasicBlock *bb);
        void setJumpIncond(BasicBlock *bb);
        void setOutCond(IRVar *condition);

    private:
        int bbId;
        std::list<IRInstr*> irInstrList;
        std::string label;
        BasicBlock* jumpCond;
        BasicBlock* jumpIncond;
        IRVar *outCond;
        CFG* cfg;
        
        list<Instruction*> CopyNotEntireList(list<Instruction*> &currentList, unsigned int beginAt, unsigned int size = 0);

};

#endif //PLD_COMP_BASICBLOCK_H
