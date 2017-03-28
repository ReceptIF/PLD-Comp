#ifndef PLD_COMP_IR_IR_H
#define PLD_COMP_IR_IR_H

#include <string>
#include <list>
#include "CFG.h"

using namespace std;

class IR {

public:
    IR(Programme *prog);
    ~IR();
    void addCFG(CFG *cfg);
    
    std::string genererAssembleur();
    
protected:
    list<CFG *> cfgs;
};

#endif //PLD_COMP_IR_IRINSTR_H
