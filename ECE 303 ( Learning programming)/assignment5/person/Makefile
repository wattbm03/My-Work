CC = g++
CCOPTS = -g -Wall
OBJECTS = PointersLab.o Person.o

PointersLab: $(OBJECTS)
	$(CC) $(CCOPTS) $(OBJECTS) -o PointersLab.exe

PointersLab.o: PointersLab.cpp
	$(CC) $(CCOPTS) -c PointersLab.cpp

Person.o: Person.cpp Person.h
	$(CC) $(CCOPTS) -c Person.cpp

clean:
	rm -f *.o *.exe
