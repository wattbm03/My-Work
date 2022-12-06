// QuadraticFunc.h 
//
// CLASS PROVIDED: QuadraticFunc
//   A quadratic function represented by three parameters: coef2, intercept, and slope 
//		y = coef2*x^2 + intercept*x + slope
//
// CONSTRUCTORS and DESTROCTOR for the QuadraticFunc class
//  QuadraticFunc() { }
//     Default constructor, no initialization
//
//  QuadraticFunc(double, double, double);
//     Initiate coef2, intercept, and slope
//
//  virtual ~QuadraticFunc() { }
//     Virtual destructor; needed since there is a virtual member function
//
// Set and Get functions for the QuadraticFunc class
//  void setCoef2(double);
//	double getCoef2() const;
//
// CONSTANT MEMBER FUNCTION: Evaluate
//	virtual double Evaluate(double) const;
//     Evaluate the quadratic function (y) with given input value (x)
//
// FRIEND NONMEMBER FUNCTION: operator <<
//	friend ostream& operator<< (ostream& os, const LinearFunc & f);
//     Print the quadratic function to ostream out, which, in turn, 
//     is then returned to the calling function

#ifndef QUADRATICFUNC_H
#define QUADRATICFUNC_H

#include "LinearFunc.h"
using namespace std;

class QuadraticFunc : public LinearFunc {
public:
	QuadraticFunc() { }
	QuadraticFunc(double, double, double);
	virtual ~QuadraticFunc() { }
	
	void setCoef2(double);
	double getCoef2() const;
	
	virtual double Evaluate(double) const;
	friend ostream& operator<< (ostream& os, const QuadraticFunc & f);
	
private:
	double coef2;
};

ostream& operator<< (ostream& os, const QuadraticFunc & f);

#endif