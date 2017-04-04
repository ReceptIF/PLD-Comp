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
  //std::cout << ast->toString() << std::endl;
  
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
  
  // Mise en place du contexte
  std::string ass;
  ass += this->ast->getNom()+":\r\n";
  ass += "\r\n";
  ass += "    pushq   %rbp \r\n";
  ass += "    movq    %rsp, %rbp \r\n";
  ass += "    subq    $"+to_string(stackSize+8)+", %rsp \r\n";
  
  // Récupération des paramètres
  std::list<Declaration *> params = ast->getParametres();
  std::list<Declaration *>::iterator i = params.begin() ;
  while ( i != params.end() ) {
    
        int indice = std::distance(params.begin(), i);
        Declaration *d = (*i);
        IRVar *var = this->getVariable(d->getNomVariable());
        
        switch(indice) {
          case 0: ass += "    mov    %rdi, "+to_string(var->getOffset())+"(%rbp) \r\n"; break;
          case 1: ass += "    mov    %rsi, "+to_string(var->getOffset())+"(%rbp) \r\n"; break;
          case 2: ass += "    mov    %rdx, "+to_string(var->getOffset())+"(%rbp) \r\n"; break;
          case 3: ass += "    mov    %rcx, "+to_string(var->getOffset())+"(%rbp) \r\n"; break;
          case 4: ass += "    mov    %r8, "+to_string(var->getOffset())+"(%rbp) \r\n"; break;
          case 5: ass += "    mov    %r9, "+to_string(var->getOffset())+"(%rbp) \r\n"; break;
        }
        
        i++;
  }
  
  ass += "\r\n";
  
  // Génération des blocs
  std::list<BasicBlock *>::iterator j = basicBlocks.begin() ;
  while ( j != basicBlocks.end() ) {
    
        string blocId = to_string((*j)->getId());
    
        ass += this->ast->getNom()+".bloc"+blocId+":\r\n";
        ass += "\r\n";
        ass += (*j)->genererAssembleur();
        ass += "\r\n";
        j++;
  }
  
  // Epilogue
  ass += this->ast->getNom()+".epilog:\r\n";
  ass += "\r\n";
  ass += "    leave\r\n";
  ass += "    ret\r\n";
  ass += "\r\n";
  
  return ass;
  
}
