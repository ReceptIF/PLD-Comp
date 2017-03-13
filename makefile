ReceptComp.exe: main.o Programme.o Fonction.o
	g++ -o ReceptComp.exe main.o Programme.o Fonction.o

main.o: main.cpp
	g++ -c main.cpp

Programme.o: Programme.cpp Programme.h Fonction.h
	g++ -c Programme.cpp

Fonction.o: Fonction.cpp Fonction.h
	g++ -c Fonction.cpp

clean:
	rm -f *.o *.exe
