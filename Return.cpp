#include "Return.h"

Return::~Return()
{

}

std::string Return::toString() 
{
    return "[I] Return "+expression->toSmallString()+"\r\n";
}
