#include "Bloc.h"

using namespace std;

Bloc::Bloc()
{
}

Bloc::~Bloc()
{
}

void Block::AjouteInstruction(Instruction* & instruction)
{
    instructions.push_back(instruction);
}
