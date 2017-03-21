COMPIL = g++
EXECNAME = ReceptifCalc
INCLLIST= ../Bloc.cpp ../Clause.cpp ../Declaration.cpp ../Expression.cpp ../ExpressionBinaire.cpp ../ExpressionConstante.cpp ../ExpressionUnaire.cpp ../ExpressionVariable.cpp ../Fonction.cpp ../For.cpp ../Instruction.cpp ../Programme.cpp ../StructCond.cpp ../Structure.cpp ../Type.cpp ../Variable.cpp ../VariableSimple.cpp ../VariableTableau.cpp ../While.cpp 
OPTIMISATIONFLAGS = -O1

default:
	flex calc.l
	bison -v -d --defines=calc.tab.h calc.y
	$(COMPIL) -g -o $(EXECNAME) $(INCLLIST) *.c $(OPTIMISATIONFLAGS)

.PHONY: clean

clean:
	rm calc.tab.* calc.output lex.yy.c $(EXECNAME)