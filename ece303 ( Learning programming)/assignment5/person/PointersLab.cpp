// Please add your name below
// Name: Breeanna Watters

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;


void PassByValue(int v)
{
    // ------------------------------------------------------------------
	// TO-DO: 
	// ------
	// Step 1: Print a text string indicating the name of the function
  cout<< "Pass By Value \n"<<endl;
	// Step 2: Modify the value of v to 10
	v=10;
	// Step 3: Print the value of v
	cout<< "v = "<< v << ".\n" <<endl;	
}

void PassByRef(int& v)
{
    // ------------------------------------------------------------------
	// TO-DO: 
	// ------
	// Step 1: Print a text string indicating the name of the function
  cout<< "Pass By reference \n"<<endl;
	// Step 2: Modify the value of v to 50
  int x;
  x=50;
  v=x;
	// Step 3: Print the value of v
	cout<< "v = "<< v << ".\n" <<endl;	
}

int main()
{
    // Part I: passing by value and passing by reference
    // --------------------------------------------------------
	// TO-DO: 
	// ------
	// Refere to the instruction file, add steps 1-9 in Part I
	int num1;
	int &rNum1 = num1;
	num1=3;
	rNum1=5;
	PassByValue(num1);
	cout<< "num1 = "<< num1 << ".\n" <<endl;
	PassByRef(rNum1);
    cout<< "rNum1 = "<< rNum1 << ".\n" <<endl;


    // Part II: pointer and memory
    // --------------------------------------------------------
	// TO-DO: 
	// ------
	// Refere to the instruction file, add steps 1-5 in Part II
	double* pDouble;
	pDouble = new double;
	*pDouble = 1.5;
	cout<< " The value of pDouble is "<< *pDouble << ".\n" <<endl;
    delete pDouble;
	cout<< " The new value of pDouble after deallocating it is "<< *pDouble << ".\n" <<endl;
    // Part III: classes and objects
    // --------------------------------------------------------
	// TO-DO: 
	// ------
	// Refere to the instruction file, add steps 1-6 in Part III
	Person *person1= new Person("Peter", 4);
	person1->print();
    person1->setName("George");
	person1->print();
	delete person1;
    return 0;
}