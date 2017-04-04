#include <iostream>
#include <fstream>

#include "Programme.h"
#include "AppelFonction.h"
#include "For.h"
#include "Structure.h"
#include "StructCond.h"
#include "IR/IR.h"

#include "Bison/calc.tab.h"
extern int yydebug;

void writeFile(std::string fileName, std::string ext, std::string content) {
    cout << ext;
    std::ofstream file;
    file.open(fileName + "." + ext);
    file << content;
    file.close();
}

int main(void) {
   //yydebug = 1;
   Programme* prog = new Programme();

   std::cout << "Etude lexicale du programme" << std::endl;
   yyparse(prog);
   
   std::cout << "Etude de la portée des variables" << std::endl;
   prog->resoudrePortees();
   std::cout << prog->toString() << std::endl;
   
#ifdef FRONTTEST
    delete prog;
    std::cout << "[Fin du programme]" << std::endl;
    return 0;
#endif

   std::cout << "Generation de l'IR" << std::endl;
   IR *ir = new IR(prog);

#ifdef OPTIMISATION
    ir->optimiser();
#endif
   
   std::cout << "Generation de l'assembleur" << std::endl;
   std::string assembleur = ir->genererAssembleur();
   std::cout << assembleur << std::endl;
   writeFile("generatedAss", "s", assembleur);

   std::cout << "Supression des objets" << std::endl;

   delete prog;
   delete ir;

   int a;
   std::cout << "[Fin du programme]" << std::endl;
   std::cin >> a;
   return 0;
}
