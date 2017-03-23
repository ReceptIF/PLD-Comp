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
    StructCond(Clause* & clause);
    ~StructCond();
    void AjouteClause(Clause* & clause);
  std::string toString();

private:
    std::list<Clause*> clauses;
    Bloc* bloc;

};

#endif //PLD_COMP_TYPEPARAMETRE_H
