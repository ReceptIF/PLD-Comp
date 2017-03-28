#include <iostream>

#include "Programme.h"
#include "AppelFonction.h"
#include "For.h"
#include "Structure.h"
#include "StructCond.h"

#include "Bison/calc.tab.h"
extern int yydebug;

int main(void) {
   //yydebug = 1;
   Programme* prog = new Programme();
   CFG *ir = new CFG();

   std::cout << "Etude lexicale du programme" << std::endl;
   yyparse(prog);
   
   std::cout << "Etude de la portée des variables" << std::endl;
   prog->resoudrePortees();
   std::cout << prog->toString() << std::endl;
   
   std::cout << "Generation de l'IR" << std::endl;
   ir->mettreEnPlaceIR(prog);
   
   std::cout << "Generation de l'assembleur" << std::endl;
   std::cout << ir->genererAssembleur(); << std::endl;

   delete prog;

   int a;
   std::cout << "[Fin du programme]" << std::endl;
   std::cin >> a;
   return 0;
}
