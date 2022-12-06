// staff.h - Implements a Staff class

#ifndef STAFF_H
#define STAFF_H

#include "employee.h"

class Staff : public Employee {
private:
	string office;

public:
	Staff() { }
	Staff(string, string, string);
	void SetOffice(string o) { office = o; }
	void printInfo() const;
};

#endif
