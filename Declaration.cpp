#include "Declaration.h"
#include "Expression.h"

Declaration::Declaration(std::string nomVar, int varType, int size)
{
    nomVariable = nomVar;
    type = varType;
    tabSize = size;
}

Declaration::~Declaration()
{
    delete init;
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

void Declaration::setInit(Expression *e) {
    init = e;
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
    std::string print;
    print += nomVariable;
    if(tabSize>0) { 
      print += "["+std::to_string(this->tabSize); 
      print += "]"; 
    } else if(tabSize==0) { 
      print += "[]"; 
    }
    print += " ("+stringifyType()+")";
    
    return print;
}

std::string Declaration::toString() 
{
    std::string print;
    print += "[I] Declaration || "+nomVariable;
    if(tabSize>0) { 
      print += "["+std::to_string(this->tabSize); 
      print += "]"; 
    } else if(tabSize==0) { 
      print += "[]"; 
    }
    print += " ("+stringifyType()+")";
    
    if(init != nullptr) { 
      print += " = "+init->toSmallString(); 
    }
    
    print += "\r\n";
    
    return print;
}

