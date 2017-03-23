#include "Fonction.h"

Fonction::Fonction(int typeRetour, Bloc *bloc, std::string nom) {
    std::cout << "Creation de la fonction " << nom << std::endl;
    this->setTypeRetour(typeRetour);
    this->setBloc(bloc);
    this->setNom(nom);
}

Fonction::~Fonction() {

}

void Fonction::setTypeRetour(int typeRetour) {
    this->typeRetour = typeRetour;
}

void Fonction::addParametre(Variable *parametre) {
    this->parametres.push_back(parametre);
}

void Fonction::setBloc(Bloc *bloc) {
    this->bloc = bloc;
}

void Fonction::setNom(std::string nom) {
    this->nom = nom;
}

int Fonction::getTypeRetour() {
    return typeRetour;
}

std::string Fonction::stringifyTypeRetour() {
  
    std::string print = "UNKNOWN";
    
    switch(this->typeRetour) {
      case INT32 :
        print = "INT32";
        break;
      case INT64 :
        print = "INT64";
        break;
      case CHAR :
        print = "CHAR";
        break;
    }
  
    return print;
}

std::list<Variable *> Fonction::getParametres() {
    return parametres;
}

Bloc *Fonction::getBloc() {
    return bloc;
}

std::string Fonction::getNom() {
    return nom;
}

std::string Fonction::toString() {
  
    std::string print;
    
    print += "[F] ~~~ Début de la fonction "+this->nom+" ~~~\r\n";
    print += "[F] ~ Type de retour : "+this->stringifyTypeRetour()+" \r\n";
    print += "[F] ~~~ Fin de la fonction "+this->nom+" ~~~\r\n";
    
    return print;
}
