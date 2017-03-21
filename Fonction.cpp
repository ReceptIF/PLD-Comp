#include "Fonction.h"

Fonction::Fonction(int typeRetour, Bloc *bloc, std::string nom) {
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

std::list<Variable *> Fonction::getParametres() {
    return parametres;
}

Bloc *Fonction::getBloc() {
    return bloc;
}

std::string Fonction::getNom() {
    return nom;
}
