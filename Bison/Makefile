default:
	flex calc.l
	bison -v --defines=calc.tab.h calc.y
	g++ -o calc *.c

clean:
	rm calc.tab.* calc.output lex.yy.c calc