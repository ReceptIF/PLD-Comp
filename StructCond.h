#ifndef PLD_COMP_TYPEPARAMETRE_H
#define PLD_COMP_TYPEPARAMETRE_H

#include <list>

#include "Structure.h"
#include "Clause.h"
#include "Bloc.h"

class Structure;
class StructCond : public Structure {

public:
    StructCond();
    StructCond(Clause* clause);
    StructCond(Bloc* b): blocElse(b) {};
    StructCond(Instruction* i);
    ~StructCond();
    void AjouteClause(Clause* clause);
    std::list<Clause *> GetClauses();
    Bloc *getElse();
    std::string toString();

private:
    std::list<Clause*> clauses;
    Bloc* blocElse;

};

#endif //PLD_COMP_TYPEPARAMETRE_H
