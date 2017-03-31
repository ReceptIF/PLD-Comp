#include "CFG.h"
using namespace std;

CFG::CFG(Fonction *fct, IR *ir)
{
  
  ast = fct;
  this->ir = ir;
  nbTemp = 0;
  
  // Ajout des paramètres dans les variables
  std::list<Declaration *> params = ast->getParametres();
  std::list<Declaration *>::iterator i = params.begin() ;
  while ( i != params.end() ) {
        Declaration *d = (*i);
        IRVar var(d->getType(), d->getNomVariable(), 0);
        this->addVariable(var);
        i++;
  }
  
  // Création des blocs
  BasicBlock *b = new BasicBlock(fct->getBloc(), this, fct->getNom()+"_bp");
  this->addBB(b);
  
}

CFG::~CFG()
{
    delete ast;
    delete ir;
    list<BasicBlock*>::iterator it;
    for(it = basicBlocks.begin(); it!=basicBlocks.end(); ++it)
    {
        delete *it;
    }
}

void CFG::addBB(BasicBlock *bb) {
  this->basicBlocks.push_back(bb);
}

void CFG::addVariable(IRVar var) {
  
    variableMap.insert(pair<string,IRVar> (var.getName(), var));
  
}

int CFG::addTempVar(int type) {
  
    int varNumber = ++nbTemp;
    std::string varName = "!r"+to_string(varNumber);
    IRVar *var = new IRVar(type,varName);
    variableMap.insert(pair<string, IRVar> (var->getName(), *var));
    
    return varNumber;
}

IRVar *CFG::getVariable(std::string nom) {
    
    std::map<std::string,IRVar>::iterator varIte;
    varIte = variableMap.find(nom);
    return &(varIte->second);
  
}

int CFG::giveOffsets() {
    int offset = -8;
    int totalSize = 0;
    
    
    std::map<std::string,IRVar>::iterator i = variableMap.begin() ;
    while ( i != variableMap.end() ) {
        i->second.setOffset(offset);
        
        switch(i->second.getType()) {
          case CHAR: offset -= 8; totalSize += 8; break;
          case INT32: offset -= 8; totalSize += 8; break;
          case INT64: offset -= 8; totalSize += 8; break;
          default: offset -= 8; totalSize += 8; break;
        }
        
        i++;
    }
    
    return totalSize;
    
}

std::string CFG::genererAssembleur() {
  
  int stackSize = this->giveOffsets();
  //cout << "Size " << stackSize << endl;
  
  std::string ass;
  ass += this->ast->getNom()+":\r\n";
  ass += "\r\n";
  ass += "    pushq   %rbp \r\n";
  ass += "    movq    %rsp, %rbp \r\n";
  ass += "    subq    $"+to_string(stackSize+8)+", %rsp \r\n";
  ass += "\r\n";
  
  std::list<BasicBlock *>::iterator i = basicBlocks.begin() ;
  while ( i != basicBlocks.end() ) {
        ass += (*i)->genererAssembleur();
        i++;
  }
  
  ass += "\r\n";
  ass += "    leave\r\n";
  ass += "    ret\r\n";
  ass += "\r\n";
  
  return ass;
  
}
