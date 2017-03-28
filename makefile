COMPIL = g++
EXECNAME = ReceptifCalc_UNIX.exe
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

 
SRC = $(wildcard *.cpp) $(wildcard Bison/*.c)
OBJS = $(SRC:.cXX=.o)


all : $(EXECNAME)

$(EXECNAME) : $(OBJS)
	$(COMPIL) -o $@ $(COMPILFLAGS) $(OPTIMISATIONFLAGS) $^
%.o : %.c
	$(COMPIL)  -o $@ $(COMPILFLAGS) $(OPTIMISATIONFLAGS) -c $<



.PHONY: clean
clean:
	$(DELETECMD) *.o *.exe
