#include "Return.h"
#include "IR/BasicBlock.h"
#include "IR/IRInstr.h"

Return::~Return()
{

}

Expression *Return::getExpression() {
    return expression;
}

std::string Return::toString() 
{
    return "[I] Return "+expression->toSmallString()+"\r\n";
}

void Return::getIR(BasicBlock *bb) {
    
    IRVar *expr = this->expression->getIR(bb);
    
    list<std::string> params;
    params.push_back("@"+expr->getName());
    IRInstr *instr = new IRInstr(bb->getCFG(),MNEMO_RETURN,params);
    bb->addInstr(instr);
    
}
