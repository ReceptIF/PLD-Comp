#ifndef PLD_COMP_PROGRAMME_H
#define PLD_COMP_PROGRAMME_H

#include <iostream>
#include <list>
#include <map>
#include <string>

#include "Fonction.h"
#include "Declaration.h"

class Programme {

public:
    Programme();
    ~Programme();
    
    void AjouteFonction(Fonction* & fonction);
    
    std::string toString();
    
    void resoudrePortees();

private:

    std::list <Fonction*> fonctions;
    
    std::map <std::string,Declaration *> variableMap;
    std::map <std::string,Fonction *> fonctionMap;

};


#endif //PLD_COMP_PROGRAMME_H
