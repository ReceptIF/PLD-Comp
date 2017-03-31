#include "Bloc.h"
#include "AppelFonction.h"
#include "While.h"
#include "For.h"
#include "StructCond.h"
#include "Return.h"

using namespace std;

Bloc::Bloc()
{
  //cout << "Creation du bloc" << endl;
}

Bloc::~Bloc()
{
  list<Instruction*>::iterator it;
  for(it = instructions.begin(); it!=instructions.end(); ++it)
  {
    delete *it;
  }
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
    
std::list<Instruction *> Bloc::getInstructions() {
  return instructions;
}

void Bloc::resoudrePortees(int *globalContext, std::list<std::string> *varStack, std::map<std::string,Declaration *> *varMap, std::list<std::string> *fctStack) {

    int stackAdding = 0;
    int localContext = ++(*globalContext);
    
    std::list<Instruction *>::iterator i = this->instructions.begin() ;
    while ( i != this->instructions.end() ) {
      
      if (dynamic_cast<Declaration *>(*i)) {
        
        Declaration *d = (Declaration *)*i;
        
        // Ajout d'une variable déclarée
        std::string varName = std::to_string(localContext)+"_"+d->getNomVariable();
        d->setNomVariable(varName);
        varMap->insert( std::pair<std::string,Declaration *>(varName,d) );
        varStack->push_back(varName);
        stackAdding++;
        
      } else if (dynamic_cast<Expression *>(*i) || dynamic_cast<ExpressionBinaire *>(*i) || dynamic_cast<ExpressionUnaire *>(*i) || dynamic_cast<ExpressionConstante *>(*i) || dynamic_cast<ExpressionVariable *>(*i) || dynamic_cast<AppelFonction *>(*i)) {
        
        Expression *e = (Expression *)*i;
        
        // Recherche de la portée
        e->resoudrePortees(varStack,varMap,fctStack);
        
      } else if (dynamic_cast<While *>(*i)) {
        
        While *w = (While *)*i;
        w->getClause()->getExpression()->resoudrePortees(varStack,varMap,fctStack);
        w->getClause()->getBloc()->resoudrePortees(globalContext, varStack, varMap, fctStack);
        
        
      } else if (dynamic_cast<For *>(*i)) {
        
        For *f = (For *)*i;
        f->GetInitialisation()->resoudrePortees(varStack,varMap,fctStack);
        f->GetCondition()->resoudrePortees(varStack,varMap,fctStack);
        f->GetIteration()->resoudrePortees(varStack,varMap,fctStack);
        f->GetBloc()->resoudrePortees(globalContext,varStack,varMap,fctStack);
        
      } else if (dynamic_cast<StructCond *>(*i)) {
        
        StructCond *s = (StructCond *)*i;
        
        std::list<Clause *> c = s->GetClauses(); 
        std::list<Clause *>::iterator j = c.begin() ;
        while ( j != c.end() ) {
          
          //(*j)->getExpression()->resoudrePortees(varStack,varMap,fctStack);
          (*j)->getBloc()->resoudrePortees(globalContext,varStack,varMap,fctStack);
          j++;
          
        }
        
        s->getElse()->resoudrePortees(globalContext,varStack,varMap,fctStack);
        
      } else if (dynamic_cast<Return *>(*i)) {
        
        Return *r = (Return *)*i;
        r->getExpression()->resoudrePortees(varStack,varMap,fctStack);
        
      }
      
      
      i++;
    }
        
    // Nettoyage du contexte
    while(stackAdding > 0) {
      varStack->pop_back();
      stackAdding--;
    }

}
