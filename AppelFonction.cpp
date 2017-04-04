#include "AppelFonction.h"
#include "IR/BasicBlock.h"
#include "IR/CFG.h"
#include <stdlib.h>

AppelFonction::AppelFonction(std::string nom)
{
    this->nomFonction = nom;
}

AppelFonction::~AppelFonction()
{

}

void AppelFonction::typage() {
  
  // TODO BUT NEED TO DO THE PORTEE
  this->type = INT32;
  
}
    
void AppelFonction::setParametres(std::list<Expression *> *list) {
  this->parametres = *list;
}

std::string AppelFonction::toString() {
  return "[I] Appel à "+this->toSmallString()+"\r\n";
}

std::string AppelFonction::toSmallString() {
  std::string print;
  print += nomFonction;
  print += "(";
  
  std::list<Expression *>::iterator i = this->parametres.begin() ;
  while ( i != this->parametres.end() ) {
      
      print += (*i)->toSmallString()+",";
      i++;
      
  }
  
  print += ")";
  return print;
}

void AppelFonction::resoudrePortees(std::list<std::string> *varStack, std::map<std::string,Declaration *> *varMap, std::list<std::string> *fctStack) {
  
  int fctExist = 0;
  
  std::list<std::string>::iterator i = fctStack->begin() ;
  while ( i != fctStack->end() && fctExist == 0) {
      
      if(*i == this->nomFonction || this->nomFonction == "putchar" || this->nomFonction == "getchar") {
        fctExist = 1;
      }  
      i++;
      
  }
  
  if(fctExist == 1) {
    Fonction *fct;
    
     std::list<Expression *>::iterator i = this->parametres.begin() ;
     while ( i != this->parametres.end() ) {
          (*i)->resoudrePortees(varStack,varMap,fctStack);
          i++;
      }
    
    // TODO: Check Args
  }
  else
  {
    std::cerr << "Erreur, la fonction appellée '"+this->nomFonction+"' n'existe pas dans ce contexte" << std::endl;
  }
}

IRVar *AppelFonction::getIR(BasicBlock *bb) {
  
    IRVar *ret = nullptr;
  
    // GESTION DE PUTCHAR
    if(nomFonction == "putchar") {
        
        std::list<Expression *>::iterator i = this->parametres.begin() ;
        Expression *inputEx = *i;
        IRVar *inputVar = inputEx->getIR(bb);
        
        list<std::string> params;
        params.push_back("%edi");
        params.push_back("@"+inputVar->getName());
        IRInstr *instr = new IRInstr(bb->getCFG(),MNEMO_ECREG,params);
        bb->addInstr(instr);
        
        list<std::string> params2;
        params2.push_back("unused");
        params2.push_back("putchar");
        IRInstr *instr2 = new IRInstr(bb->getCFG(),MNEMO_CALL,params2);
        bb->addInstr(instr2);
        
    } else {
      // AUTRES FONCTIONS
      
      int tmpVar = bb->getCFG()->addTempVar(this->type);
      ret = bb->getCFG()->getVariable("!r"+to_string(tmpVar));
      
      list<std::string> params;
      params.push_back("unused");
      params.push_back(this->nomFonction);
      
      // Ajout paramètres
      std::list<Expression *>::iterator i = this->parametres.begin() ;
       while ( i != this->parametres.end() ) {
            
            IRVar *varParam = (*i)->getIR(bb);
            params.push_back("@"+varParam->getName());
            i++;
            
      }
      
      IRInstr *instr = new IRInstr(bb->getCFG(),MNEMO_CALL,params);
      bb->addInstr(instr);
        
      list<std::string> params2;
      params2.push_back("@"+ret->getName());
      params2.push_back("%rax");
      IRInstr *instr2 = new IRInstr(bb->getCFG(),MNEMO_ECREG,params2);
      bb->addInstr(instr2); 
      
    }
  
  return ret;
}
