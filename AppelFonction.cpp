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
