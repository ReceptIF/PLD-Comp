OUTPUTNAME = Assemblif
DELETECMD = rm

ifeq ($(OS),Windows_NT)
	OUTPUTNAME = Assemblif.exe
    DELETECMD = del /Q
endif

all : 
	g++ -Wall main.cpp -o $(OUTPUTNAME) -O3

clean :
	$(DELETECMD) Assemblif.exe
