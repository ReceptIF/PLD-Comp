#include "IRInstr.h"
#include "CFG.h"
using namespace std;

IRInstr::IRInstr(CFG *cfg, int mnemonique, list<std::string> params)
{
    this->cfg = cfg;
    this->mnemo = mnemonique;
    this->parametres = params;
    
}

IRInstr::~IRInstr()
{

}

std::string IRInstr::genererAssembleur() {
  
  std::string ass;
  
  int nbParams = parametres.size();
  std::string p0 = "";
  std::string p1 = "";
  std::string p2 = "";
  
  std::list<std::string>::iterator i = parametres.begin();
  if(nbParams >= 1) { p0 = *i; i++; }
  if(nbParams >= 2) { p1 = *i; i++; }
  if(nbParams >= 3) { p2 = *i; i++; }
    
  p0 = transParam(p0);
  p1 = transParam(p1);
  p2 = transParam(p2);
  
  switch(mnemo) {
    case MNEMO_CONST :
      ass += "    movl   "+p1+", "+p0+"\r\n";
      break;
      
    case MNEMO_ECR :
      ass += "    mov    "+p1+", "+p0+"\r\n";
      break;
      
    case MNEMO_CALL :
      ass += "    call   "+p1+"\r\n";
      break;
      
    case MNEMO_PLUS :
      ass += "    mov    "+p2+", %r15\r\n";
      ass += "    add    "+p1+", "+p2+"\r\n";
      ass += "    mov    "+p2+", "+p0+"\r\n";
      ass += "    mov    %r15, "+p2+"\r\n";
      break;
      
    case MNEMO_MOINS :
      ass += "    mov    "+p2+", %r15\r\n";
      ass += "    sub    "+p1+", "+p2+"\r\n";
      ass += "    mov    "+p2+", "+p0+"\r\n";
      ass += "    mov    %r15, "+p2+"\r\n";
      break;
      
    case MNEMO_MULT :
      ass += "    mov    "+p2+", %r15\r\n";
      ass += "    imul   "+p1+", "+p2+"\r\n";
      ass += "    mov    "+p2+", "+p0+"\r\n";
      ass += "    mov    %r15, "+p2+"\r\n";
      break;
      
    case MNEMO_DIV :
      ass += "    mov    "+p2+", %r15\r\n";
      ass += "    idiv   "+p1+", "+p2+"\r\n";
      ass += "    mov    "+p2+", "+p0+"\r\n";
      ass += "    mov    %r15, "+p2+"\r\n";
      break;
      
  }
  
  return ass;
}

std::string IRInstr::transParam(std::string p) {
  if(p[0] == '@') {
    
    std::string nomVar = p.substr(1);
    IRVar *var = cfg->getVariable(nomVar);
    int varOffset = var->getOffset();
    
    /*if(var->isTmp()) {
      int regValue = stoi(var->getName().substr(1));
      regValue %= 5;
      regValue += 9;
      p = "%r"+to_string(regValue);
    } else {*/
      p = to_string(varOffset)+"(%rbp)";
    //}
  } 
  
  return p;
}
