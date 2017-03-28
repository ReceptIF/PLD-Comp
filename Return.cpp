#include "Return.h"

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
