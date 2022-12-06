#include <iostream>
#include "faculty.h"
#include "staff.h"

int main() {
	Faculty x("Chen", "16359", "Danielle");
	Staff y("Danielle", "16362", "ET327");
	x.printInfo();
	y.printInfo();

	return 0;
}
