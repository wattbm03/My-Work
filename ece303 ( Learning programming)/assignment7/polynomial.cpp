// Please add your name below
// Name: Breeanna Watters

#include <algorithm> // Provides copy functions
#include <iostream>  // Provides ostream
#include "polynomial.h"
using namespace std;

polynomial::polynomial()
{
	// TO-DO: 
	// ------
	//    Allocate space for coef (an array of size one)
	//    initiate coef and set current_degree
	coef= new double[0];
	coef[0]=0;
	current_degree=0;
	
	
}

polynomial::polynomial(double c)
{
	// TO-DO: 
	// ------
	//    Allocate space for coef (an array of size one)
	//    initiate coef and set current_degree
	current_degree=0;
	coef= new double[current_degree];
	coef[current_degree]=c;
	
	
}

polynomial::polynomial(const double* coef_array, unsigned int size)
{
	// TO-DO: 
	// ------
	//    Allocate space for coef
	//    Copy content from coef_array into coef
	current_degree=size-1;
	coef=new double[current_degree];
	copy(coef_array, coef_array+current_degree, coef);


	
	
}

polynomial::polynomial(const polynomial& source)
{
	// TO-DO: 
	// ------
	//    Allocate space for coef
	//    Copy content from coef in source into coef
		coef= new double[source.current_degree];
		current_degree=source.current_degree;
		copy(source.coef, source.coef+current_degree, coef);
}

polynomial::~polynomial()
{
	// TO-DO: 
	// ------
	//    Release memory of ceof
	delete [] coef;
}


polynomial& polynomial::operator =(const polynomial& source)
{
	// TO-DO: 
	// ------
	//    Do a deep copy from source to this polynomial
	//    Return a reference to this polynomial
	if(this == &source) return *this;
	if(this->current_degree != source.current_degree)
	{
		double* new_coef = new double[source.current_degree];
		delete [] coef;
		coef=new_coef;
	}
 	current_degree=source.current_degree;
 	copy(source.coef, source.coef + current_degree, coef);
	
}

void polynomial::scale(double c)
{ 
	for (size_t i=0; i<=current_degree; i++) coef[i] *= c; 
}

void polynomial::reduce( )
{
	// TO-DO: 
	// ------	
	//    If the coefficient of current_degree term is zero, 
	//    then find the highest degree term with a non-zero coefficient, 
	//    update current_degree, and free unnecessary memory spaces 
	//    (i.e., make sure the size of coef is equal to current_degree+1)
	//current_degree=sizeof(coef)-1;
	int i=current_degree;
	for( i; i<=current_degree; i--)
	{ 
		if(abs(coef[i])==1e-5){continue;}
		else
		{
		current_degree=i;
		break;
		}}
	copy(coef, coef+current_degree, coef);
}
	
polynomial polynomial::operator +(const polynomial& p)
{
	// TO-DO: 
	// ------	
	//    Return a polynomial p1, where p1.coef stores the sum 
	//    of this->coef and p.coef
	//    Make sure to call reduce() function in the end
	polynomial& p1= *this;
	for(int i=0; i<(p.current_degree+1); i++)
		{for(int j=0; j<(p1.current_degree+1); j++){
			p1.coef[i]=p1.coef[i]+p.coef[i];
		}}
	reduce();
	return p1;
	
	
}

polynomial polynomial::operator -(const polynomial& p)
{
	// TO-DO: 
	// ------	
	//    Return a polynomial p1, where p1.coef stores the difference 
	//    of this->coef and p.coef
	//    Make sure to call reduce() function in the end
		polynomial& p1= *this;
	for(int i=0; i<(p.current_degree+1); i++)
		{for(int j=0; j<(p1.current_degree+1); j++){
			p1.coef[i]=p1.coef[i]-p.coef[i];
		}}
	reduce();
	return p1;
	
	
}

ostream& operator <<(ostream& os, const polynomial& p)
{
    // Each iteration of this loop prints one term of the polynomial:
    for (unsigned int i=p.current_degree; i>=0; i--) 
    {
		// Get the coefficient:
		double number = p.coef[i];
		
		if (abs(number) < 1e-5) // coefficient is zero
		{ 
			if (p.current_degree==0) 
			{
				os << "0";
				break;
			}
			else
			{
				if (i==0) 
					break;
				else 
					continue;
			}
		}
		
		// Print a sign
		if (number < 0)
		{
		    os << "-";
		    number = -number;
		}
		else if (i < p.current_degree)
		    os << "+";

		// Print the coefficient, variable x, and exponent
		if ((abs(number - 1.0) > 1e-5) || (i == 0))
		    os << number;
		
		if (i > 0)
		    os << 'x';
		
		if (i > 1)
		    os << '^' << i;
		
		if (i==0) break;
    }

    return os;     //return the output stream
}