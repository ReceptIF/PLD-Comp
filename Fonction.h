#ifndef PLD_COMP_FONCTION_H
#define PLD_COMP_FONCTION_H

#include <list>
#include <iostream>
#include <string>

#include "Variable.h"
#include "Bloc.h"

class Fonction {

public:
    Fonction(int typeRetour, Bloc* bloc, std::string nom);
    ~Fonction();

    void setTypeRetour(int typeRetour);

    void addParametre(Variable* parametre);

    void setBloc(Bloc* bloc);

    void setNom(std::string nom);

    int getTypeRetour();

    std::list<Variable*> getParametres();

    Bloc* getBloc();

    std::string getNom();

private:
    int typeRetour;
    std::list <Variable*> parametres;
    Bloc* bloc;
    std::string nom;

};


#endif //PLD_COMP_FONCTION_H
