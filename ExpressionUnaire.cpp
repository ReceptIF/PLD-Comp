#include "ExpressionUnaire.h"
#include "IR/IRInstr.h"
#include "IR/BasicBlock.h"
#include "IR/IRVar.h"
#include "IR/CFG.h"

ExpressionUnaire::ExpressionUnaire(Expression *e, int symb, int pref)
{
  this->expression1 = e;
  this->symbole = symb;
  this->prefixe = pref;
}

ExpressionUnaire::~ExpressionUnaire()
{
    delete expression1;
}

void ExpressionUnaire::setExpression1(Expression* expression)
{
	expression1 = expression;
}

void ExpressionUnaire::setSymbole(int symbole)
{
	this->symbole = symbole;
}

void ExpressionUnaire::setPrefixe(int prefixe)
{
	this->prefixe = prefixe;
}

Expression *ExpressionUnaire::getExpression1()
{
	return expression1;
}

int ExpressionUnaire::getSymbole()
{
	return symbole;
}

int ExpressionUnaire::getPrefixe()
{
	return prefixe;
}

void ExpressionUnaire::typage() {
  
  this->expression1->typage();
  this->type = expression1->getType();
  
}

std::string ExpressionUnaire::toString() {
  if(!prefixe) {
    return "[I] ExprUnaire | "+expression1->toSmallString()+stringifySymbole(symbole)+"\r\n";
  }else {
    return "[I] ExprUnaire | "+stringifySymbole(symbole)+expression1->toSmallString()+"\r\n";
  }
}

std::string ExpressionUnaire::toSmallString() {
  if(prefixe) {
    return expression1->toSmallString()+stringifySymbole(symbole);
  }else {
    return stringifySymbole(symbole)+expression1->toSmallString();
  }
}

void ExpressionUnaire::resoudrePortees(std::list<std::string> *varStack, std::map<std::string,Declaration *> *varMap, std::list<std::string> *fctStack) {
  expression1->resoudrePortees(varStack, varMap, fctStack);
}

IRVar *ExpressionUnaire::getIR(BasicBlock *bb) {
  
  IRVar *ret = nullptr;
  IRVar *ope = this->expression1->getIR(bb);
  
  if(this->prefixe == 1 && this->symbole == DPLUS) {
      // INCREMENTATIONS PREFIXEES
      
      int tmpVar = bb->getCFG()->addTempVar(this->type);
      IRVar *one = bb->getCFG()->getVariable("!r"+to_string(tmpVar));
      
      list<std::string> params;
      params.push_back("@!r"+to_string(tmpVar));
      params.push_back("$1");
      IRInstr *instr = new IRInstr(bb->getCFG(),MNEMO_CONST,params);
      bb->addInstr(instr);
      
      list<std::string> params2;
      params2.push_back("%rax");
      params2.push_back("@!r"+to_string(tmpVar));
      IRInstr *instr2 = new IRInstr(bb->getCFG(),MNEMO_ECR,params2);
      bb->addInstr(instr2);
      
      list<std::string> params3;
      params3.push_back("@"+ope->getName());
      params3.push_back("%rax");
      params3.push_back("@"+ope->getName());
      IRInstr *instr3;
      
      switch(this->symbole) {
        case DPLUS: 
          instr3 = new IRInstr(bb->getCFG(),MNEMO_PLUS,params3);
          break;
      }
      bb->addInstr(instr3);
      
      ret = ope;
      
  } else if(this->prefixe == 0 && this->symbole == DPLUS) {
    // INCREMENTATION SUFFIXEE
    
    int tmpVar = bb->getCFG()->addTempVar(this->type);
    IRVar *one = bb->getCFG()->getVariable("!r"+to_string(tmpVar));
    
    int tmpVar2 = bb->getCFG()->addTempVar(this->type);
    ret = bb->getCFG()->getVariable("!r"+to_string(tmpVar));
    
    list<std::string> params;
    params.push_back("@"+one->getName());
    params.push_back("$1");
    IRInstr *instr = new IRInstr(bb->getCFG(),MNEMO_CONST,params);
    bb->addInstr(instr);
    
    list<std::string> params2;
    params2.push_back("%rax");
    params2.push_back("@"+one->getName());
    IRInstr *instr2 = new IRInstr(bb->getCFG(),MNEMO_ECR,params2);
    bb->addInstr(instr2);
    
    list<std::string> params3;
    params3.push_back("%rdx");
    params3.push_back("@"+ope->getName());
    IRInstr *instr3 = new IRInstr(bb->getCFG(),MNEMO_ECR,params3);
    bb->addInstr(instr3);
    
    list<std::string> params4;
    params4.push_back("@"+ret->getName());
    params4.push_back("%rdx");
    IRInstr *instr4 = new IRInstr(bb->getCFG(),MNEMO_ECR,params4);
    bb->addInstr(instr4);
    
    list<std::string> params5;
    params5.push_back("@"+ope->getName());
    params5.push_back("%rax");
    params5.push_back("%rdx");
    IRInstr *instr5;
    
    switch(this->symbole) {
      case DPLUS: 
        instr5 = new IRInstr(bb->getCFG(),MNEMO_PLUS,params5);
        break;
    }
    bb->addInstr(instr5);
    
  }
  
  return ret;
}
