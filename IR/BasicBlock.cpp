#include "BasicBlock.h"
using namespace std;

BasicBlock::BasicBlock()
{

}

BasicBlock::BasicBlock(Fonction *fct) {
  
    this->label = fct->getNom();
  
}

BasicBlock::~BasicBlock()
{

}

std::string BasicBlock::genererAssembleur() {
  
  
  
}
