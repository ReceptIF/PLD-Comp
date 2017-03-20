#ifndef PLD_COMP_FONCTION_H
#define PLD_COMP_FONCTION_H

#include <list>
#include <string>

#include "Variable.h"
#include "Bloc.h"

class Fonction {

public:
    Fonction();
    ~Fonction();

private:
    int typeRetour;
    std::list <Variable*> parametres;
    Bloc* bloc;
    string nom;

};


#endif //PLD_COMP_FONCTION_H
