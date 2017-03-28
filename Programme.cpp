#include "Programme.h"

using namespace std;

Programme::Programme()
{
  std::cout << "Creation du programme" << std::endl;
}

Programme::~Programme()
{

}

void Programme::AjouteFonction(Fonction* & fonction)
{
    std::cout << "Ajout de la fonction "+fonction->getNom()+" au programme" << std::endl;
    fonctions.push_back(fonction);
}

std::map <std::string, Fonction *> Programme::getFonctions() {
  return this->fonctionMap;
}

std::map <std::string, Declaration *> Programme::getVariables() {
  return this->variableMap;
}

string Programme::toString()
{
  
  string printer;
  
  printer += "[P] ----- Début du Programme -----\r\n";
  
  std::list<Fonction*>::iterator ite;
  for(ite=fonctions.begin();ite!=fonctions.end();ite++) {
      printer += (*ite)->toString();
  }
  
  printer += "[P] ----- Fin du Programme -----\r\n";
  
  return printer;
}

void Programme::resoudrePortees() {
  
  std::list<std::string> varStack;
  std::list<std::string> fctStack;
  
  int *globalContext = new int();
  *globalContext = 31080;
  int localContext = *globalContext;
  
  std::list<Fonction*>::iterator ite;
  for(ite=fonctions.begin();ite!=fonctions.end();ite++) {
      
      fonctionMap.insert ( std::pair<std::string,Fonction *>((*ite)->getNom(),(*ite)) );
      fctStack.push_back((*ite)->getNom());
      (*ite)->resoudrePortees(globalContext, &varStack, &variableMap, &fctStack);
      
  }
  
}
