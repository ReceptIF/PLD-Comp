#include "IRInstr.h"
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
  
  switch(mnemo) {
    case MNEMO_CONST :
      ass += "    movl   "+p0+", "+p1+"\r\n";
      break;
      
    case MNEMO_CALL :
      ass += "    call   "+p1+"\r\n";
      break;
      
  }
  
  return ass;
}
