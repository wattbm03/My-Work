// Person.h - Implements a Person class

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
public:
	Person() { }
	Person(string, unsigned int);
	
	void setName(string);
	string getName() const;
	void setAge(unsigned int);
	unsigned int getAge() const;
	
	void print() const;
	
private:
	string name;
	unsigned int age;
};
#endif