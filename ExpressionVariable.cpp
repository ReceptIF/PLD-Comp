#include "ExpressionVariable.h"
#include "IR/BasicBlock.h"
#include "IR/CFG.h"

ExpressionVariable::ExpressionVariable(std::string nomVariable)
{
  this->variable = new VariableSimple(nomVariable);
  this->type = INT64;
}

ExpressionVariable::ExpressionVariable(std::string nomVariable, Expression *e)
{
  this->variable = new VariableTableau(nomVariable,e);
  this->type = INT64;
}

ExpressionVariable::~ExpressionVariable()
{
  delete variable;
}

Variable *ExpressionVariable::getVariable() {
  return variable;
}

void ExpressionVariable::typage() {
  
  // La portée doit avoir été fait au préalable pour réaliser le typage
  
}

std::string ExpressionVariable::toString() {
  return "[I] ExprVar | "+variable->toSmallString()+"\r\n";
}

std::string ExpressionVariable::toSmallString() {
  return variable->toSmallString();
}

void ExpressionVariable::resoudrePortees(std::list<std::string> *varStack, std::map<std::string,Declaration *> *varMap, std::list<std::string> *fctStack) {
  
    std::string name = variable->getNom();
    int finded = 0;
    
    std::list<std::string> localStack = *varStack;
    localStack.reverse();
    std::cout << "PRE WHILE COUT" << endl;
    std::list<std::string>::iterator i = localStack.begin() ;
    while ( i != localStack.end() && finded == 0 ) {
      
        std::string stackName = *i;
        int underPlace = stackName.find_first_of('_');
        stackName = stackName.substr (underPlace+1); 
        
        if(stackName == name) {
          finded = 1;
          this->variable->setNom(*i);
          std::map<std::string, Declaration *>::iterator varDec = varMap->find(*i);
          if(varDec != varMap->end()) {
            this->type = varDec->second->getType();
          }
        }
        
        i++;
        std::cout << "WHILE COUT" << endl;
    }
    std::cout << "BITE COUT" << endl;
    
    std::cout << "GROSCHIBRE " << name << " finded ? " << to_string(finded) << std::endl;
    
    if(finded == 0) {
      std::cerr << "La variable '"+name+"' n'existe pas dans ce contexte" << std::endl;
    }
}

IRVar *ExpressionVariable::getIR(BasicBlock *bb) {
  
  IRVar *var = bb->getCFG()->getVariable(this->getVariable()->getNom());
  return var;
  
}
