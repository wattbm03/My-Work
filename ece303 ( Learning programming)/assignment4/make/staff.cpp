#include <iostream>
#include "staff.h"

using namespace std;

Staff::Staff(string n, string t, string o) : Employee(n, t) { office = o; }

void Staff::printInfo() const {
	cout << name << "'s number is " << tel 
		<< ", office address is " << office << endl;
}
