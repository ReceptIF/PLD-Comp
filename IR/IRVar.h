#ifndef PLD_COMP_IR_IRVAR_H
#define PLD_COMP_IR_IRVAR_H

#include <string>

using namespace std;

class IRVar {

public:
    IRVar(int aType, string aName, int aOffset):type(aType),name(aName),offset(aOffset),tmp(0) {} ;
    IRVar(int aType, string aName):type(aType),name(aName),offset(0),tmp(1) {} ;
    ~IRVar();
    std::string getName();
    void setOffset(int off);
    int getType();
    int getOffset();
    int isTmp();
    
protected:
    int tmp;
    int type;
    string name;
    int offset;
    
};

#endif //PLD_COMP_IR_IRVAR_H
