#ifndef PLD_COMP_WHILE_H
#define PLD_COMP_WHILE_H

#include "Structure.h"
#include "Clause.h"

class Structure;
class While : public Structure {

public:
  While(Clause *aClause):clause(aClause) {};
  While(Expression *expression, Bloc *bloc);
  While(Expression *expression, Instruction *instruction);
  ~While();
  Clause *getClause();
  std::string toString();
  void getIR(BasicBlock *bb, list<Instruction *> endInstr);

protected:
	Clause* clause;

};

#endif //PLD_COMP_WHILE_H
