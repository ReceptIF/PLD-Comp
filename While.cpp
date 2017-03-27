#include "While.h"

While::While(Expression *expression, Bloc *bloc) {
  
  Clause *c = new Clause(expression,bloc);
  clause = c;
  
}

While::While(Expression *expression, Instruction *instruction) {
  
  Bloc *bloc = new Bloc();
  bloc->AjouteInstruction(instruction);
  
  Clause *c = new Clause(expression,bloc);
  clause = c;
  
}

While::~While() {
  delete clause;
}

Clause *While::getClause() {
  return clause;
}

std::string While::toString() {
  std::string print;
  print += "[S] === Début de la structure WHILE ===\r\n";
  print += "[S] Cond : "+clause->getExpression()->toSmallString()+"\r\n";
  print += clause->getBloc()->toString();
  print += "[S] === Fin de la structure WHILE ===\r\n";
  return print;
}
