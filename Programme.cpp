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
