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
      ass += "    mov    "+p1+", %rax\r\n";
      ass += "    mov    %rax, "+p0+"\r\n";
      break;
      
    case MNEMO_ECREG :
      ass += "    mov    "+p1+", "+p0+"\r\n";
      break;
      
    case MNEMO_CALL :
      ass += "    call   "+p1+"\r\n";
      break;
      
    case MNEMO_PLUS :
      ass += "    mov    "+p1+", %rdx\r\n";
      ass += "    mov    "+p2+", %rax\r\n";
      ass += "    add    %rdx, %rax\r\n";
      ass += "    mov    %rax, "+p0+"\r\n";
      
      break;
      
    case MNEMO_MOINS :
      ass += "    mov    "+p1+", %rax\r\n";
      ass += "    sub    "+p2+", %rax\r\n";
      ass += "    mov    %rax, "+p0+"\r\n";
      break;
      
    case MNEMO_MULT :
      ass += "    mov    "+p1+", %rax\r\n";
      ass += "    imul   "+p2+", %rax\r\n";
      ass += "    mov    %rax, "+p0+"\r\n";
      break;
      
    case MNEMO_DIV :
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    cqto \r\n";
      ass += "    idivq   "+p2+" \r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
      break;
      
    case MNEMO_DEGAL :
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    cmp    "+p2+", %rax \r\n";
      ass += "    sete   %al  \r\n";
      ass += "    movzbl %al, %eax \r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
      break;
      
    case MNEMO_NOTEQ :
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    cmp    "+p2+", %rax \r\n";
      ass += "    setne  %al  \r\n";
      ass += "    movzbl %al, %eax \r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
      break;
      
    case MNEMO_INF :
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    cmp    "+p2+", %rax \r\n";
      ass += "    setl   %al  \r\n";
      ass += "    movzbl %al, %eax \r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
      break;
      
    case MNEMO_INFEQ :
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    cmp    "+p2+", %rax \r\n";
      ass += "    setle   %al  \r\n";
      ass += "    movzbl %al, %eax \r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
      break;
      
    case MNEMO_SUP :
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    cmp    "+p2+", %rax \r\n";
      ass += "    setg   %al  \r\n";
      ass += "    movzbl %al, %eax \r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
      break;
      
    case MNEMO_SUPEQ :
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    cmp    "+p2+", %rax \r\n";
      ass += "    setge  %al  \r\n";
      ass += "    movzbl %al, %eax \r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
      break;
      
    case MNEMO_MOD :
      ass += "    mov    "+p2+", %rax \r\n";
      ass += "    mov    $0, %rdx\r\n";
      ass += "    divq   "+p1+"\r\n";
      ass += "    mov    %rdx, "+p0+" \r\n";
      break;
      
    case MNEMO_AND :
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    and    "+p2+", %rax\r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
      break;
      
    case MNEMO_OR :
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    or     "+p2+", %rax\r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
      break;
      
    case MNEMO_XOR :
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    xor    "+p2+", %rax\r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
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
