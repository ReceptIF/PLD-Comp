#ifndef PLD_COMP_PROGRAMME_H
#define PLD_COMP_PROGRAMME_H

#include <iostream>
#include <list>
#include <string>

#include "Fonction.h"

class Programme {

public:

    Programme();
    ~Programme();
    void AjouteFonction(Fonction* & fonction);
    std::string toString();

private:

    std::list <Fonction*> fonctions;

};


#endif //PLD_COMP_PROGRAMME_H
