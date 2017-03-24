#include "AppelFonction.h"

AppelFonction::AppelFonction(std::string nom)
{
    this->nomFonction = nom;
}

AppelFonction::~AppelFonction()
{

}

std::string AppelFonction::toString() {
  return "[I] Appel à la fonction "+nomFonction+"\r\n";
}

std::string AppelFonction::toSmallString() {
  return nomFonction;
}
