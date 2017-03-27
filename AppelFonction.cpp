#include "AppelFonction.h"

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
    
    // TODO Check Args
  }
  else
  {
    std::cerr << "Erreur, la fonction appellée '"+this->nomFonction+"' n'existe pas dans ce contexte" << std::endl;
  }
}
