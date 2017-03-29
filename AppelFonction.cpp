#include "AppelFonction.h"
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
      
      if(*i == this->nomFonction) {
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

void AppelFonction::getIR(BasicBlock *bb) {
  
    // Gestion des paramètres
    std::list<Expression *>::iterator i = this->parametres.begin() ;
    while ( i != this->parametres.end() ) {
      
          // Temporaire
          if (dynamic_cast<ExpressionConstante *>(*i)) {
            
              ExpressionConstante *c = (ExpressionConstante *)*i;
              std::string edi = "%edi";
              //char ch = itoa();
              std::string constVal = "$"+to_string(c->getValeur());
              constVal += "";
              
              std::list<std::string> params;
              params.push_back(edi);
              params.push_back(constVal);
              
              IRInstr *instr = new IRInstr(bb->getCFG(),MNEMO_CONST,params);
              bb->addInstr(instr);
              
          }
          i++;
          
    }
    
    // Appel à la fct
    if(nomFonction == "putchar") {
        list<std::string> params;
        params.push_back("nop");
        params.push_back(nomFonction);
        IRInstr *instr = new IRInstr(bb->getCFG(),MNEMO_CALL,params);
        bb->addInstr(instr);
    }
  
}
