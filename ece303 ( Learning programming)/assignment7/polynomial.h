// FILE: polynomial.h
// CLASS PROVIDED: polynomial
//     A polynomial has one variable x, real number coefficients, and
//     non-negative integer exponents. Such a polynomial can be viewed
//     as having the form:
//       A[n]*x^n + A[n-1]*x^(n-1) + ... A[2]*x^2 + A[1]*x + A[0]
//     where the A[n] are the real number coefficients and x^i represents
//     the variable x raised to the ith power. The coefficient A[0] is
//     called the "constant" or "zeroth" term of the polynomial.
//
//
// CONSTRUCTORS and DESTROCTOR 
//   polynomial( )
//   polynomial(double c)
//	 polynomial(const double* coef_array, unsigned int size)
//   polynomial(const polynomial& source)
//   ~polynomial()
//
// ASSIGNMENT OPERATOR
//   polynomial& operator =(const polynomial& source)
//
// CONSTANT MEMBER FUNCTIONS 
//   unsigned int degree( ) const
//     Returns current_degree
//
//   double coefficient(unsigned int exponent) const
//     If exponent <= current_degree, returns coefficient at
//	   specified exponent of this polynomial; otherwise, return 0.0
//
// MODIFICATION MEMBER FUNCTIONS 
//   void scale(double c)
//     Scale all coefficients by c
//
//	 void reduce( )
//	   Free unnecessary space for coef and adjust current_degree
//
// CONSTANT OPERATORS 
//   polynomial operator +(const polynomial& p);
//     Add two polynomials
//
//   polynomial operator -(const polynomial& p);
//	   Subtract two polynomials

// NON-MEMBER OPERATOR
//   ostream& operator << (ostream& out, const polynomial& p)
//     Print the polynomial to ostream out, which, in turn, 
//     is then returned to the calling function

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
using namespace std;

class polynomial {
private:
	double* coef;
	unsigned int current_degree;
	
public:
	// CONSTRUCTORS and DESTRUCTOR
	polynomial();
	polynomial(double c);
	polynomial(const double* coef_array, unsigned int number);
	polynomial(const polynomial& source);
	~polynomial();

	// ASSIGNMENT OPERATOR
	polynomial& operator =(const polynomial& source);

	// CONSTANT MEMBER FUNCTIONS
	unsigned int degree() const { return current_degree; }
	
	double coefficient(unsigned int exponent) const 
	{ return (exponent<=current_degree ? coef[exponent] : 0.0); }
	
  	// MODIFICATION MEMBER FUNCTIONS
	void scale(double c); 	
	void reduce();

	// operator overloading through member function
	polynomial operator +(const polynomial& p);
	polynomial operator -(const polynomial& p);
	
	// operator overloading through friend function
	friend ostream& operator <<(ostream& os, const polynomial& p);
};

// NON-MEMBER OPERATORS
ostream& operator <<(ostream& os, const polynomial& p);

#endif
