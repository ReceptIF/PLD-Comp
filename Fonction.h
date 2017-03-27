#ifndef PLD_COMP_FONCTION_H
#define PLD_COMP_FONCTION_H

#include <list>
#include <map>
#include <iostream>
#include <string>

#include "Declaration.h"
#include "Bloc.h"

class Fonction {

public:
    Fonction(int typeRetour, Bloc* bloc, std::string nom);
    ~Fonction();

    void setTypeRetour(int typeRetour);

    void addParametre(Declaration* parametre);

    void setBloc(Bloc* bloc);

    void setNom(std::string nom);
    
    void setParametres(std::list<Declaration *> *decList);

    int getTypeRetour();
    
    std::string stringifyTypeRetour();

    std::list<Declaration*> getParametres();

    Bloc* getBloc();

    std::string getNom();
    
    std::string toString();
    
    void resoudrePortees(int *globalContext, std::list<std::string> *varStack, std::map<std::string,Declaration *> *varMap, std::list<std::string> *fctStack);

private:
    int typeRetour;
    std::list <Declaration*> parametres;
    Bloc* bloc;
    std::string nom;

};


#endif //PLD_COMP_FONCTION_H
