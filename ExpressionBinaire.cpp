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

IRVar *ExpressionBinaire::getIR(BasicBlock *bb) {
  
  IRVar *ret = nullptr;
  
  if(this->symbole == EGAL) {
    if(dynamic_cast<ExpressionVariable *>(this->expression1)) {
      // On ne peut faire des affectations que vers des variables
      
      ExpressionVariable *lvar = (ExpressionVariable *) this->expression1;
      IRVar *right = this->expression2->getIR(bb);
        
      list<std::string> params;
      params.push_back("@"+lvar->getVariable()->getNom());
      params.push_back("@"+right->getName());
      IRInstr *instr = new IRInstr(bb->getCFG(),MNEMO_ECR,params);
      bb->addInstr(instr);
      
    } else { std::cerr << "[ERROR] La partie gauche d'une affectation n'est pas une variable" << std::endl; }
  
  } else if (this->symbole == PLUS || this->symbole == MOINS || this->symbole == MULT || this->symbole == DIV 
                || this->symbole == DEGAL || this->symbole == DIFF || this->symbole == INF || this->symbole == INFEQ
                || this->symbole == SUPEQ || this->symbole == SUP || this->symbole == MOD || this->symbole == AND
                || this->symbole == OR) {
    
      IRVar *left = this->expression1->getIR(bb);
      IRVar *right = this->expression2->getIR(bb);
          
      int tmpVar = bb->getCFG()->addTempVar(this->type);
      ret = bb->getCFG()->getVariable("!r"+to_string(tmpVar));
      
      list<std::string> params;
      params.push_back("@"+ret->getName());
      params.push_back("@"+left->getName());
      params.push_back("@"+right->getName());
      IRInstr *instr;
      
      switch(this->symbole) {
        case PLUS:
          instr = new IRInstr(bb->getCFG(),MNEMO_PLUS,params);
          break;
      
        case MOINS:
          instr = new IRInstr(bb->getCFG(),MNEMO_MOINS,params);
          break;
      
        case MULT:
          instr = new IRInstr(bb->getCFG(),MNEMO_MULT,params);
          break;
      
        case DIV:
          instr = new IRInstr(bb->getCFG(),MNEMO_DIV,params);
          break;
      
        case DEGAL:
          instr = new IRInstr(bb->getCFG(),MNEMO_DEGAL,params);
          break;
      
        case DIFF:
          instr = new IRInstr(bb->getCFG(),MNEMO_NOTEQ,params);
          break;
      
        case INF:
          instr = new IRInstr(bb->getCFG(),MNEMO_INF,params);
          break;
      
        case INFEQ:
          instr = new IRInstr(bb->getCFG(),MNEMO_INFEQ,params);
          break;
      
        case SUP:
          instr = new IRInstr(bb->getCFG(),MNEMO_SUP,params);
          break;
      
        case SUPEQ:
          instr = new IRInstr(bb->getCFG(),MNEMO_SUPEQ,params);
          break;
      
        case MOD:
          instr = new IRInstr(bb->getCFG(),MNEMO_MOD,params);
          break;
      
        case AND:
          instr = new IRInstr(bb->getCFG(),MNEMO_AND,params);
          break;
      
        case OR:
          instr = new IRInstr(bb->getCFG(),MNEMO_OR,params);
          break;
        
      }
       bb->addInstr(instr);
    
  } else if (this->symbole == PLUSEQ || this->symbole == MOINSEQ || this->symbole == MULTEQ || this->symbole == DIVEQ
             || this->symbole == ANDEQ || this->symbole == OREQ) {
    
      IRVar *left = this->expression1->getIR(bb);
      IRVar *right = this->expression2->getIR(bb);
          
      int tmpVar = bb->getCFG()->addTempVar(this->type);
      IRVar *inter = bb->getCFG()->getVariable("!r"+to_string(tmpVar));
      
      ret = left;
      
      // CALCULATOR OPERATION
      list<std::string> params;
      params.push_back("@"+inter->getName());
      params.push_back("@"+left->getName());
      params.push_back("@"+right->getName());
      IRInstr *instr;
      
      switch(this->symbole) {
        case PLUSEQ:
          instr = new IRInstr(bb->getCFG(),MNEMO_PLUS,params);
          break;
      
        case MOINSEQ:
          instr = new IRInstr(bb->getCFG(),MNEMO_MOINS,params);
          break;
      
        case MULTEQ:
          instr = new IRInstr(bb->getCFG(),MNEMO_MULT,params);
          break;
      
        case DIVEQ:
          instr = new IRInstr(bb->getCFG(),MNEMO_DIV,params);
          break;
      
        case ANDEQ:
          instr = new IRInstr(bb->getCFG(),MNEMO_AND,params);
          break;
      
        case OREQ:
          instr = new IRInstr(bb->getCFG(),MNEMO_OR,params);
          break;
        
      }
      bb->addInstr(instr);
      
      // AFFECTATION OPERATION
      list<std::string> params2;
      params2.push_back("@"+left->getName());
      params2.push_back("@"+inter->getName());
      IRInstr *instr2 = new IRInstr(bb->getCFG(),MNEMO_ECR,params2);
      bb->addInstr(instr2);
  }
  
  return ret;
  
}
