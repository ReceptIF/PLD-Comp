#include "StructCond.h"

using namespace std;

StructCond::StructCond()
{

}

StructCond::StructCond(Clause* clause)
{
    AjouteClause(clause);
}

StructCond::StructCond(Instruction* instruction)
{
    Bloc *b = new Bloc();
    b->AjouteInstruction(instruction);
    this->blocElse = b;
}

StructCond::~StructCond()
{

}

void StructCond::AjouteClause(Clause* clause)
{
    clauses.push_back(clause);
}

std::string StructCond::toString() {
  std::string print;
  print += "[S] === Début de la structure IF/ELSE ===\r\n";
 
  std::list<Clause *>::iterator i = this->clauses.begin() ;
  while ( i != this->clauses.end() ) {
    print += "[S] = Début de la clause ("+(*i)->getExpression()->toSmallString()+")\r\n";
    print += (*i)->getBloc()->toString();
    print += "[S] = Fin de la clause\r\n";
    i++;
  }
  
  if(blocElse != nullptr) {
    print += "[S] = Début de la clause ELSE\r\n";
    print += this->blocElse->toString();
    print += "[S] = Fin de la clause\r\n";
  }
 
  print += "[S] === Fin de la structure IF/ELSE ===\r\n";
  return print;
}
