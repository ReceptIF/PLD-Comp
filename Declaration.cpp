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

std::string Declaration::stringifyType() {
  
    std::string print = "UNKNOWN";
    
    switch(this->type) {
      case INT32 :
        print = "INT32";
        break;
      case INT64 :
        print = "INT64";
        break;
      case CHAR :
        print = "CHAR";
        break;
      case VOID :
        print = "VOID";
        break;
    }
  
    return print;
}

std::string Declaration::toSmallString() 
{
    return nomVariable+" ("+stringifyType()+")";
}

std::string Declaration::toString() 
{
    return "[I] Declaration || "+nomVariable+" ("+stringifyType()+")\r\n";
}
