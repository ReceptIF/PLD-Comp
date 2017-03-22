ReceptComp.exe: main.o Programme.o Fonction.o ExpressionBinaire.o
	g++ -o ReceptComp.exe main.o Programme.o Expression.o Fonction.o

main.o: main.cpp
	g++ -c main.cpp

Programme.o: Programme.cpp Programme.h Fonction.h
	g++ -c Programme.cpp

Fonction.o: Fonction.cpp Fonction.h
	g++ -c Fonction.cpp

Instruction.o: Instruction.cpp Instruction.h
	g++ -c Instruction.cpp

Expression.o: Expression.cpp Expression.h Instruction.h
	g++ -c Expression.cpp

ExpressionBinaire.o: ExpressionBinaire.cpp ExpressionBinaire.h Expression.h
	g++ -c ExpressionBinaire.cpp

clean:
	rm -f *.o *.exe
