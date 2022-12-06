// employee.h - Implements an Employee class

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

class Employee {
protected:
	string name;
	string tel;

public:
	Employee()  { }
	Employee(string, string);
	void setInfo(string n, string t) { name = n; tel = t; }
	void printInfo() const;
};

#endif
