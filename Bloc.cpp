#include "Bloc.h"

using namespace std;

Bloc::Bloc()
{
  cout << "Creation du bloc" << endl;
}

Bloc::~Bloc()
{
}

void Bloc::AjouteInstruction(Instruction* instruction)
{
    instructions.push_back(instruction);
}
