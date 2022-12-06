#include <iostream>
#include "employee.h"

using namespace std;

Employee::Employee(string n, string t) {
	name = n;
	tel = t;
}

void Employee::printInfo() const{
	cout << name << "'s number is " << tel << endl;
}
