#include "CFG.h"
#include "IR.h"
using namespace std;

CFG::CFG(Fonction *fct, IR *ir)
{
  
  ast = fct;
  this->ir = ir;
  nbTemp = 0;
  nbBloc = 0;
  
  // Ajout des paramètres dans les variables
  std::cout << ast->toString() << std::endl;
  std::list<Declaration *> params = ast->getParametres();
  std::list<Declaration *>::iterator i = params.begin() ;
  while ( i != params.end() ) {
        Declaration *d = (*i);
        IRVar var(d->getType(), d->getNomVariable(), 0);
        if(d->getTabSize() > 0) { var.setSize(d->getTabSize()); }
        this->addVariable(var);
        i++;
  }
  
  // Création des blocs
  BasicBlock *b = new BasicBlock(fct->getBloc()->getInstructions(), this, fct->getNom()+"_bp");
  this->addBB(b,0);
  
}

CFG::~CFG()
{
  
    list<BasicBlock*>::iterator it;
    for(it = basicBlocks.begin(); it!=basicBlocks.end(); ++it)
    {
        delete *it;
    }
}

void CFG::addBB(BasicBlock *bb, int rank) {
  if(rank != 0) {
    this->basicBlocks.push_back(bb);
  } else if(rank == 0) {
    list<BasicBlock*>::iterator it = this->basicBlocks.begin();
    this->basicBlocks.insert(it,bb);
  }
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

int *CFG::getNbBloc() {
    
    return &(nbBloc);
  
}

Fonction *CFG::getAST() {
    
    return ast;
  
}

int CFG::giveOffsets() {
    int offset = -8;
    int totalSize = 0;
    
    
    std::map<std::string,IRVar>::iterator i = variableMap.begin() ;
    while ( i != variableMap.end() ) {
        i->second.setOffset(offset);
        int tabSize = i->second.getSize();
        
        switch(i->second.getType()) {
          case CHAR: offset -= 8*tabSize; totalSize += 8*tabSize; break;
          case INT32: offset -= 8*tabSize; totalSize += 8*tabSize; break;
          case INT64: offset -= 8*tabSize; totalSize += 8*tabSize; break;
          default: offset -= 8*tabSize; totalSize += 8*tabSize; break;
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
    
        string blocId = to_string((*i)->getId());
    
        ass += this->ast->getNom()+".bloc"+blocId+":\r\n";
        ass += "\r\n";
        ass += (*i)->genererAssembleur();
        ass += "\r\n";
        i++;
  }
  
  ass += this->ast->getNom()+".epilog:\r\n";
  ass += "\r\n";
  ass += "    leave\r\n";
  ass += "    ret\r\n";
  ass += "\r\n";
  
  return ass;
  
}
