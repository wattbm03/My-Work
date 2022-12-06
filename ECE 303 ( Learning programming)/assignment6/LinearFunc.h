// LinearFunc.h 
//
// CLASS PROVIDED: LinearFunc
//   A linear function represented by two parameters: intercept and slope 
//		y = slope*x + intercept
//
// CONSTRUCTORS and DESTROCTOR for the LinearFunc class
//  LinearFunc() { }
//     Default constructor, no initialization
//
//  LinearFunc(double, double);
//     Initiate slope and intercept
//
//  virtual ~LinearFunc() { }
//     Virtual destructor; needed since there is a virtual member function
//
// Set and Get functions for the LinearFunc class
//  void setIntercept(double);
//	double getIntercept() const;
//	void setSlope(double);
//	double getSlope() const;
//
// CONSTANT MEMBER FUNCTION: Evaluate
//	virtual double Evaluate(double) const;
//     Evaluate the linear function (y) with given input value (x)
//
// FRIEND NONMEMBER FUNCTION: operator <<
//	friend ostream& operator<< (ostream& os, const LinearFunc & f);
//     Print the linear function to ostream out, which, in turn, 
//     is then returned to the calling function

#ifndef LINEARFUNC_H
#define LINEARFUNC_H
#include <iostream>
using namespace std;

class LinearFunc {
public:
	LinearFunc() { }
	LinearFunc(double, double);
	virtual ~LinearFunc() { }
	
	void setIntercept(double);
	double getIntercept() const;
	void setSlope(double);
	double getSlope() const;
	
	virtual double Evaluate(double) const;
	friend ostream& operator<< (ostream& os, const LinearFunc & f);
	
protected:
	double intercept;
	double slope;
};

ostream& operator<< (ostream& os, const LinearFunc & f);

#endif