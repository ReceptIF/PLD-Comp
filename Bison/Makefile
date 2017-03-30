COMPIL = g++
EXECNAME = ReceptifCalc
INCLLIST= ../AppelFonction.cpp ../Bloc.cpp ../Break.cpp ../Clause.cpp ../Declaration.cpp ../Expression.cpp ../ExpressionBinaire.cpp ../ExpressionConstante.cpp ../ExpressionUnaire.cpp ../ExpressionVariable.cpp ../Fonction.cpp ../For.cpp ../Instruction.cpp ../Programme.cpp ../Return.cpp ../StructCond.cpp ../Structure.cpp ../Type.cpp ../Variable.cpp ../VariableSimple.cpp ../VariableTableau.cpp ../While.cpp
COMPILFLAGS = -std=c++1y
OPTIMISATIONFLAGS = -O1
DELETECMD = rm

BISONCMD = bison
FLEXCMD = flex

ifeq ($(OS),Windows_NT)
    #Windows stuff
    EXECNAME = ReceptifCalc_WIN.exe
    DELETECMD = del /Q
    BISONCMD = win_bison
	FLEXCMD = win_flex
	COMPILFLAGS = -std=gnu++1z -DGTEST_OS_CYGWIN=1
endif

default:
	$(FLEXCMD) calc.l
	$(BISONCMD) -v -d -t --defines=calc.tab.h calc.y
#	$(COMPIL) -g -o  $(EXECNAME) -DYYDEBUG=1 $(INCLLIST) *.c $(COMPILFLAGS) $(OPTIMISATIONFLAGS)


.PHONY: clean
clean:
	$(DELETECMD) calc.tab.* calc.output lex.yy.c $(EXECNAME)
