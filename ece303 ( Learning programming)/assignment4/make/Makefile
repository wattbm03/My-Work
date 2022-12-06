CC = g++
CCOPTS = -g -Wall
OBJECTS = test.o employee.o faculty.o staff.o

test: $(OBJECTS)
	$(CC) $(CCOPTS) $(OBJECTS) -o test.exe

test.o: test.cpp
	$(CC) $(CCOPTS) -c test.cpp

employee.o: employee.cpp employee.h
	$(CC) $(CCOPTS) -c employee.cpp
	
faculty.o: faculty.cpp faculty.h
	$(CC) $(CCOPTS) -c faculty.cpp

staff.o: staff.cpp staff.h
	$(CC) $(CCOPTS) -c staff.cpp

clean:
	rm -f *.o *.exe
