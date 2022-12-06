CC = g++
CCOPTS = -g -Wall
OBJECTS = InheritanceLab.o QuadraticFunc.o LinearFunc.o

InheritanceLab: $(OBJECTS)
	$(CC) $(CCOPTS) $(OBJECTS) -o InheritanceLab.exe

InheritanceLab.o: InheritanceLab.cpp
	$(CC) $(CCOPTS) -c InheritanceLab.cpp

QuadraticFunc.o: QuadraticFunc.cpp QuadraticFunc.h
	$(CC) $(CCOPTS) -c QuadraticFunc.cpp
	
LinearFunc.o: LinearFunc.cpp LinearFunc.h
	$(CC) $(CCOPTS) -c LinearFunc.cpp

clean:
	rm -f *.o *.exe
