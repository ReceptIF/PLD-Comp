#include "Bloc.h"

using namespace std;

Bloc::Bloc()
{
  //cout << "Creation du bloc" << endl;
}

Bloc::~Bloc()
{
}

std::string Bloc::toString() {
  std::string print;
  
  print += "[B] ### Début du bloc\r\n";
  
  std::list<Instruction *>::iterator i = this->instructions.begin() ;
  while ( i != this->instructions.end() ) {
      
      print += (*i)->toString();
      i++;
      
  }
  
  print += "[B] ### Fin du bloc\r\n";
  
  return print;
}

void Bloc::AjouteInstruction(Instruction* instruction)
{
    instructions.push_back(instruction);
}
