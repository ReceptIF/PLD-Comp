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

int IRInstr::getMnemo() {
  return this->mnemo;
}

std::string IRInstr::genererAssembleur() {
  
  std::string ass;
  
  int nbParams = parametres.size();
  std::string p0 = "";
  std::string p1 = "";
  std::string p2 = "";
  std::string p3 = "";
  std::string p4 = "";
  std::string p5 = "";
  std::string p6 = "";
  std::string p7 = "";
  
  std::list<std::string>::iterator i = parametres.begin();
  if(nbParams >= 1) { p0 = *i; i++; }
  if(nbParams >= 2) { p1 = *i; i++; }
  if(nbParams >= 3) { p2 = *i; i++; }
  if(nbParams >= 4) { p3 = *i; i++; }
  if(nbParams >= 5) { p4 = *i; i++; }
  if(nbParams >= 6) { p5 = *i; i++; }
  if(nbParams >= 7) { p6 = *i; i++; }
  if(nbParams >= 8) { p7 = *i; i++; }
  
  p0 = transParam(p0);
  p1 = transParam(p1);
  p2 = transParam(p2);
  p3 = transParam(p3);
  p4 = transParam(p4);
  p5 = transParam(p5);
  p6 = transParam(p6);
  p7 = transParam(p7);
  
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
    
      if(p2 != "") { ass += "    mov    "+p2+", %rdi \r\n"; }
      if(p3 != "") { ass += "    mov    "+p3+", %rsi \r\n"; }
      if(p4 != "") { ass += "    mov    "+p4+", %rdx \r\n"; }
      if(p5 != "") { ass += "    mov    "+p5+", %rcx \r\n"; }
      if(p6 != "") { ass += "    mov    "+p6+", %r8 \r\n"; }
      if(p7 != "") { ass += "    mov    "+p7+", %r9 \r\n"; }
        
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
      ass += "    xor    "+p2+", %rax\r\n";
      ass += "    cmpq   $0, %rax \r\n";
      ass += "    sete   %al \r\n";
      ass += "    movzbl %al, %eax \r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
      break;
      
    case MNEMO_NOTEQ :
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    xor    "+p2+", %rax\r\n";
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
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    mov    $0, %rdx\r\n";
      ass += "    idivw   "+p2+"\r\n";
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
      
    case MNEMO_DINF :
      ass += "    mov    "+p2+", %rax \r\n";
      ass += "    mov    %eax, %edx \r\n";
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    mov    %edx, %ecx \r\n";
      ass += "    shl    %cl, %rax\r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
      break;
      
    case MNEMO_DSUP :
      ass += "    mov    "+p2+", %rax \r\n";
      ass += "    mov    %eax, %edx \r\n";
      ass += "    mov    "+p1+", %rax \r\n";
      ass += "    mov    %edx, %ecx \r\n";
      ass += "    sar    %cl, %rax\r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
      break;
      
    case MNEMO_NOT :
      ass += "    cmpq   $0, "+p1+" \r\n";
      ass += "    sete   %al \r\n";
      ass += "    movzbl %al, %eax \r\n";
      ass += "    mov    %rax, "+p0+" \r\n";
      break;
      
    case MNEMO_RETURN :
      ass += "    mov    "+p0+", %rax \r\n";
      ass += "    jmp     "+this->cfg->getAST()->getNom()+".epilog \r\n";
      break;
      
  }
  
  return ass;
}

std::string IRInstr::transParam(std::string p) {
  
  if(p[0] == '@') {
    
    std::string nomVar;
    int stringSize = p.size();
    
    if(p[stringSize-1] == ']') {
      
      int debIndice = p.find_first_of('[');
      int nbSize = stringSize-debIndice-2;
      nomVar = p.substr(1,stringSize-nbSize-3);
      
      int indice =  std::stoi(p.substr(debIndice+1,nbSize));
      int unitSize;
    
      IRVar *var = cfg->getVariable(nomVar);
      
      switch(var->getType()) {
        default: unitSize=8; break;
      }
    
      int varOffset = var->getOffset()-(indice*unitSize);
      
      p = to_string(varOffset)+"(%rbp)";
      
    } else {
      
      nomVar = p.substr(1);
    
      IRVar *var = cfg->getVariable(nomVar);
      int varOffset = var->getOffset();
      
      p = to_string(varOffset)+"(%rbp)";
      
    }
    
  } 
  
  return p;
}
