#ifndef PLD_COMP_IR_IRINSTR_H
#define PLD_COMP_IR_IRINSTR_H

#include <string>
#include <list>

class CFG;
using namespace std;

class IRInstr {

public:
    IRInstr();
    ~IRInstr();
    
    void genererAssembleur();
    
protected:
    CFG *cfg;
    int mnemo;
    
    list<string> parametres;
    // == PARAMETRES ==
    // 3 opérandes : dest, p1, p2
    // MNEMO_CONST : dest, const
    // MNEMO_CALL  : dest, label, p1, p2, ... , pn
    // MNEMO_LECT  : dest, source
    // MNEMO_ECR   : dest, source
};

#endif //PLD_COMP_IR_IRINSTR_H
