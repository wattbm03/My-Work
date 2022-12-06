// Please add your name below
// Name: Breeanna Watters

#include <iostream>
#include "LinearFunc.h"
#include "QuadraticFunc.h"

using namespace std;

int main()
{
	// TO-DO: 
	// ------
	// Refer to the instruction file, add steps 1-9
	LinearFunc lFunc(-3, 1); 
  cout<< lFunc;
	LinearFunc *pFunc;
  pFunc=&lFunc;
  cout<<pFunc->Evaluate(2)<<"    at x=2\n\n";

  QuadraticFunc qFunc(1, 0 , 25);
  cout<<qFunc;
    pFunc=&qFunc;
  cout<<pFunc->Evaluate(5)<<"     at x=5\n";
    return 0;
}