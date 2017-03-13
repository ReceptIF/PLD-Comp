#ifndef PLD_COMP_PROGRAMME_H
#define PLD_COMP_PROGRAMME_H

#include <iostream>
#include <list>

#include "Fonction.h"

using namespace std;

class Programme {

public:

Programme();
~Programme();

private:

list<Fonction> fonctions;	

};


#endif //PLD_COMP_PROGRAMME_H
