CC = g++
CCOPTS = -g -Wall
OBJECTS = FileIOLab.o Record.o

FileIOLab: $(OBJECTS)
	$(CC) $(CCOPTS) $(OBJECTS) -o FileIOLab.exe

FileIOLab.o: FileIOLab.cpp
	$(CC) $(CCOPTS) -c FileIOLab.cpp

Record.o: Record.cpp Record.h
	$(CC) $(CCOPTS) -c Record.cpp
	
clean:
	rm -f *.o *.exe