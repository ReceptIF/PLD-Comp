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
  
  std::string ass;
  ass += this->label+":\r\n";
  ass += "\r\n";
  ass += "    retq\r\n";
  ass += "\r\n";
  
  return ass;
  
}
