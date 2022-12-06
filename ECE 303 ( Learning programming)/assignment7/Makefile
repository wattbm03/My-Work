CC = g++
CCOPTS = -g -Wall
OBJECTS = polytest.o polynomial.o

polytest: $(OBJECTS)
	$(CC) $(CCOPTS) $(OBJECTS) -o polytest.exe

polytest.o: polytest.cpp
	$(CC) $(CCOPTS) -c polytest.cpp

polynomial.o: polynomial.cpp polynomial.h
	$(CC) $(CCOPTS) -c polynomial.cpp

clean:
	rm -f *.o *.exe