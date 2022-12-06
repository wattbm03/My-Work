// faculty.h - Implements a Faculty class

#ifndef FACULTY_H
#define FACULTY_H

#include "employee.h"

class Faculty : public Employee {
private:
	string secretary;

public:
	Faculty() { }
	Faculty(string, string, string);
	void setSecretary(string s) { secretary = s; }
	void printInfo() const;
};
#endif
