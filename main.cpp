#include "Programme.h"

extern int yydebug;

int main(void) {
   //yydebug = 1;
   Programme* prog = new Programme();

   std::cout << "Etude lexicale du programme" << std::endl;
   yyparse(prog);
   
   std::cout << "Etude de la portée des variables" << std::endl;
   prog->resoudrePortees();
   
   std::cout << prog->toString() << std::endl;

   delete prog;

   int a;
   std::cout << "[Fin du programme]" << std::endl;
   std::cin >> a;
   return 0;
}
