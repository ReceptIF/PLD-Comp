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
  
  std::list<std::string>::iterator i = parametres.begin();
  if(nbParams >= 1) { p0 = *i; i++; }
  if(nbParams >= 2) { p1 = *i; i++; }
    
  if(p0[0] == '@') {
    std::string nomVar = p0.substr(1);
    IRVar *var = cfg->getVariable(nomVar);
    int varOffset = var->getOffset();
    p0 = to_string(varOffset)+"(%rbp)";
  }
    
  if(p1[0] == '@') {
    std::string nomVar = p1.substr(1);
    IRVar *var = cfg->getVariable(nomVar);
    int varOffset = var->getOffset();
    p1 = to_string(varOffset)+"(%rbp)";
  }
  
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
      
  }
  
  return ass;
}
