default:
	flex calc.l
	bison -v -d --defines=calc.tab.h calc.y
	g++ -g -o calc ../Expression.cpp ../Instruction.cpp *.c 

clean:
	rm calc.tab.* calc.output lex.yy.c calc