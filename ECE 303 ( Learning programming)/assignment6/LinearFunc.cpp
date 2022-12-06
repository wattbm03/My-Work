// Please add your name below
// Name: Breeanna Watters

#include <iostream>
#include "LinearFunc.h"
double epsilon = 0.000001;

using namespace std;
LinearFunc::LinearFunc (double slope1, double intercept1)
{
    this->intercept = intercept1;
    this->slope = slope1;
}
void LinearFunc:: setIntercept(double intercept1)
{
    this->intercept = intercept1;
}
double LinearFunc:: getIntercept() const
{
    return this-> intercept;
}
void LinearFunc::setSlope(double slope1)
{
    this->slope = slope1;
}
double LinearFunc::getSlope() const
{
    return this->slope;
}
double LinearFunc::Evaluate(double x) const
{
double y;
y=slope*x+intercept;
return y;
}
ostream& operator<< (ostream& os, const LinearFunc & f)
{
    if(f.intercept<0)
    {   
        if(abs(abs(f.slope)-1)<epsilon)
        {
            if(f.slope>0)
               os<<"x-"<<abs(f.intercept)<<endl;
            else
                os<<"-x-"<<abs(f.intercept)<<endl;}
        else if(abs(f.slope)<epsilon)
            os<<f.intercept<<endl;
        else
            os<<f.slope<<"x-"<<abs(f.intercept)<<endl;
    }
    else if (f.intercept>0)
    {   if(abs(abs(f.slope)-1)<epsilon){
            if(f.slope>0)
                os<<"x+"<<f.intercept<<endl;
            else
                os<<"-x+"<<f.intercept<<endl;}
        else if(abs(f.slope)<epsilon)
            os<<f.intercept<<endl;
        else
           os<<f.slope<<"x+"<<f.intercept<<endl;
    }
    else
     {
       if(abs(abs(f.slope)-1)<epsilon)
       {
         if(f.slope>0)
           os<<"x"<<endl;
         else
          os<<"-x"<<endl;
        }
        else if(abs(f.slope)<epsilon)
            os<<"0"<<endl;
        else
        os<<f.slope<<"x"<<endl;
      }
      
 return os;
}