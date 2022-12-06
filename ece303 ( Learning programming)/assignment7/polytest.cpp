// FILE: polytest.cpp
// An Interactive test program for the polynomial ADT

#include <iostream>        // Provides cout and cin
#include "polynomial.h"    // Provides the polynomial class
using namespace std;

// PROTOTYPES for functions used by this test program:
void set_poly(polynomial& p);
void view(const polynomial& test);

int main()
{
	cout << "Testing the default constructor.\n";
	polynomial p[2]; // calls default constructor
	cout << "Polynomials A and B have been initilized." << endl;
	cout << "A: ";
	view(p[0]);
	cout << "B: ";
	view(p[1]);

	cout << "\nTesting the constructor with constant input.\n";
	polynomial x_const(1.0);
	cout << "X_const: ";
	view(x_const);
	
	cout << "\nTesting the constructor with array input.\n";
	for (unsigned int i=0; i<2; i++) {
		cout << "Set up degree and coefficients for " << char('A' + i) << ": \n";
		set_poly(p[i]);
		
		cout << char('A' + i) << ": ";
		view(p[i]);
	}
    
	cout << "\nTesting copy constructor.\n";
	polynomial C(p[0]);
	C.scale(2.0);
	cout << "A: ";
	view(p[0]);
	cout << "C: ";
	view(C);

	cout << "\nTesting assignment operator =\n";
	polynomial D = p[1];
	D.scale(2.0);
	cout << "B: ";
	view(p[1]);
	cout << "D: ";
	view(D);
	
	cout << "\nTesting reduce()\n";
	cout << "Set up degree and coefficients for E: \n";
	polynomial E;
	set_poly(E);
	cout << "E: ";
	view(E);
	
	cout << "\nTesting operators + and -\n";
	cout << "A: ";
	view(p[0]);
	cout << "B: ";
	view(p[1]);
	cout << "A + B: ";
	view(p[0] + p[1]);
	
	cout << "A - B: ";
	view(p[0] - p[1]);

	return 0;
}

// set_poly: Prompt user to set degree and coefficients for the current polynomial. 
void set_poly(polynomial& p)
{
	unsigned int degree;
	cout << "enter degree=";
	cin >> degree;
    
	cout << "enter " << degree + 1 << " coefficients (from constant term up):";
	double* coef = new double[degree+1];
	for (unsigned int i=0; i<=degree; i++)
		cin >> coef[i];
        
	polynomial new_poly(coef, degree+1); // call constructor with array input
	delete [] coef;
	
	p = new_poly; // call assignment operator
}

// view: Print the test polynomial to cout (via <<). 
void view(const polynomial& test)
{
	cout << test
		<< " (degree is " << test.degree( ) << ")" << endl;
}
