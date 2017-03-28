#ifndef PLD_COMP_BASICBLOCK_H
#define PLD_COMP_BASICBLOCK_H

class BasicBlock {

    public:
        BasicBlock();
        ~BasicBlock();

        void genererAssembleur();

    private:
        std::list<IRInstr*> irInstrList;
        BasicBlock* inCondSucc;
        BasicBlock* condSucc;
        CFG* cfg;

};

#endif //PLD_COMP_BASICBLOCK_H
