#include "Declaration.h"

Declaration::Declaration()
{

}

Declaration::Declaration(std::string nomVar, int varType)
{
    nomVariable = nomVar;
    type = varType;
}

Declaration::~Declaration()
{

}

void Declaration::setNomVariable(std::string nV)
{
    nomVariable = nV;
}
std::string Declaration::getNomVariable()
{
    return nomVariable;
}

void Declaration::setType(int t)
{
    type = t;
}
int Declaration::getType()
{
    return type;
}