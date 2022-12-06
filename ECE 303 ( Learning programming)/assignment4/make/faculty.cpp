#include <iostream>
#include "faculty.h"

using namespace std;

Faculty::Faculty(string n, string t, string s) : Employee(n, t) { secretary = s; }

void Faculty::printInfo() const {
	cout << name << "'s number is " << tel << ", secretary is " << secretary << endl;
}
