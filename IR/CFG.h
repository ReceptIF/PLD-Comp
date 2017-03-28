#ifndef PLD_COMP_CFG_H
#define PLD_COMP_CFG_H

class CFG {

public:
    CFG();
    ~CFG();

private:
    std::map <std::string,Declaration *> variableMap;
    std::map <std::string,Fonction *> fonctionMap;
    std::list<BasicBlock*> basicBlocks;

};

#endif //PLD_COMP_CFG_H
