#include "ExpressionBinaire.h"
#include "ExpressionVariable.h"
#include "IR/IRVar.h"
#include "IR/BasicBlock.h"
#include "IR/CFG.h"

ExpressionBinaire::ExpressionBinaire(Expression *e1, Expression *e2, int symb)
{
  this->expression1 = e1;
  this->expression2 = e2;
  this->symbole = symb;
}

ExpressionBinaire::~ExpressionBinaire()
{
	delete expression1;
	delete expression2;
}

void ExpressionBinaire::setExpression1(Expression* expression)
{
	this->expression1 = expression;
}

void ExpressionBinaire::setExpression2(Expression* expression)
{
	this->expression2 = expression;
}

void ExpressionBinaire::setSymbole(int &symbole)
{
	this->symbole = symbole;
}

Expression *ExpressionBinaire::getExpression1()
{
	return expression1;
}

Expression *ExpressionBinaire::getExpression2()
{
	return expression2;
}

int ExpressionBinaire::getSymbole()
{
	return symbole;
}

void ExpressionBinaire::typage() {
  
  this->expression1->typage();
  this->expression2->typage();
  
  int type1 = expression1->getType();
  int type2 = expression2->getType();
  
  int resType;
  
  if(symbole == EGAL) {
    // Affectation
    resType = type2;
    
  } else if(symbole == PLUS || symbole == MULT || symbole == DIV || 
            symbole == MOINS || symbole == PLUS || symbole == MOD ||
            symbole == PLUSEQ || symbole == MULTEQ || symbole == DIVEQ ||
            symbole == MOINSEQ || symbole == MODEQ) {
    // Opération calculatoire
    if(type1 == INT64 && type2 == INT64) {
      resType = INT64;
    } else if((type1 == INT64 && type2 == INT32) || (type1 == INT32 && type2 == INT64)) {
      resType = INT64;
    } else if((type1 == INT64 && type2 == CHAR) || (type1 == CHAR && type2 == INT64)) {
      resType = INT64;
    } else if(type1 == INT32 && type2 == INT32) {
      resType = INT32;
    } else if((type1 == CHAR && type2 == INT32) || (type1 == INT32 && type2 == CHAR)) {
      resType = INT32;
    } else if(type1 == CHAR && type2 == CHAR) {
      resType = CHAR;
    } 
    
  } else if(symbole == DAND || symbole == DOR || symbole == DEGAL || 
            symbole == INFEQ || symbole == SUPEQ || symbole == DIFF || 
            symbole == INF || symbole == SUP || symbole == ANDEQ || 
            symbole == OREQ || symbole == SUPEQ || symbole == DIFF) {
    // Opération booléenne
    resType = INT32;
    
  } else if(symbole == AND || symbole == OR || symbole == XOR) {
    // Opération bit à bit
    resType = INT64;
  
  }else if(symbole == DSUP || symbole == DINF) {
    // Opération de shift
    resType = type1;
    
  }
  
  this->type = resType;
}

std::string ExpressionBinaire::toString() {
  return "[I] ExprBinaire | "+expression1->toSmallString()+" "+this->stringifySymbole(symbole)+" "+expression2->toSmallString()+"\r\n";
}

std::string ExpressionBinaire::toSmallString() {
  return "("+expression1->toSmallString()+" "+this->stringifySymbole(symbole)+" "+expression2->toSmallString()+")";
}


void ExpressionBinaire::resoudrePortees(std::list<std::string> *varStack, std::map<std::string,Declaration *> *varMap, std::list<std::string> *fctStack) {
  expression1->resoudrePortees(varStack, varMap, fctStack);
  expression2->resoudrePortees(varStack, varMap, fctStack);
}

void ExpressionBinaire::getIR(BasicBlock *bb) {
  
  if(this->symbole == EGAL) {
    if(dynamic_cast<ExpressionVariable *>(this->expression1)) {
      // Pour l'instant on gère que les affectations 
      // variable = constante & variable = variable
      
      ExpressionVariable *lvar = (ExpressionVariable *) this->expression1;
      
      if(dynamic_cast<ExpressionConstante *>(this->expression2)) {
        ExpressionConstante *rval = (ExpressionConstante *) this->expression2;
        
        list<std::string> params;
        params.push_back("@"+lvar->getVariable()->getNom());
        params.push_back("$"+to_string(rval->getValeur()));
        IRInstr *instr = new IRInstr(bb->getCFG(),MNEMO_CONST,params);
        bb->addInstr(instr);
        
      }else if(dynamic_cast<ExpressionVariable *>(this->expression2)) {
        ExpressionVariable *rvar = (ExpressionVariable *) this->expression2;
        
        list<std::string> params;
        params.push_back("%rax");
        params.push_back("@"+rvar->getVariable()->getNom());
        IRInstr *instr = new IRInstr(bb->getCFG(),MNEMO_ECR,params);
        bb->addInstr(instr);
        
        list<std::string> params2;
        params2.push_back("@"+lvar->getVariable()->getNom());
        params2.push_back("%rax");
        IRInstr *instr2 = new IRInstr(bb->getCFG(),MNEMO_ECR,params2);
        bb->addInstr(instr2);
        
      }
      
    } else { std::cerr << "[ERROR] La partie gauche d'une affectation n'est pas une variable" << std::endl; }
  }
  
}
