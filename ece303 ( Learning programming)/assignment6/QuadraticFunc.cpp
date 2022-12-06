// Please add your name below
// Name: Breeanna Watters

#include <iostream>
#include "LinearFunc.h"
#include "QuadraticFunc.h"
double epsilon1 = 0.000001;
using namespace std;

QuadraticFunc::QuadraticFunc(double coef21, double slope1, double intercept1):LinearFunc(slope1, intercept1)
{
    this->coef2=coef21;
   this->intercept = intercept1;
    this->slope = slope1;
}
void QuadraticFunc::setCoef2(double coef21)
{
    this->coef2=coef21;
}
double QuadraticFunc::getCoef2() const
{
   return  this -> coef2;
}
double QuadraticFunc::Evaluate(double x) const
{
 double y;
 y=coef2*x*x+slope*x+intercept;
 return y;
} 
ostream& operator<< (ostream& os, const QuadraticFunc & f)
{   
  if(f.intercept<0)
    {
      if(abs(abs(f.coef2)-1)<epsilon1)
      {
        if(f.coef2>0)
        {
          if(abs(abs(f.slope)-1)<epsilon1)
          {
            if(f.slope>0)
              os<<"x*x+x-"<<abs(f.intercept)<<endl;
            else
              os<<"x*x-x-"<<abs(f.intercept)<<endl;
          }
            else if(abs(f.slope)<epsilon1)
            os<<"x*x-"<<f.intercept<<endl;
            else if (f.slope>0)
             os<<"x*x+"<<f.slope<<"x-"<<abs(f.intercept)<<endl;
            else
             os<<"x*x-"<<abs(f.slope)<<"x-"<<abs(f.intercept)<<endl;
        }
        else
        {
          if(abs(abs(f.slope)-1)<epsilon1)
          {
            if(f.slope>0)
              os<<"-x*x+x-"<<abs(f.intercept)<<endl;
            else
              os<<"-x*x-x-"<<abs(f.intercept)<<endl;
          }
            else if(abs(f.slope)<epsilon1)
            os<<"-x*x-"<<abs(f.intercept)<<endl;
            else if (f.slope>0)
             os<<"-x*x+"<<f.slope<<"x-"<<abs(f.intercept)<<endl;
            else
             os<<"-x*x-"<<abs(f.slope)<<"x-"<<abs(f.intercept)<<endl;
          }
        }
        else if(abs(f.coef2)<epsilon1)
        {
          if(abs(abs(f.slope)-1)<epsilon1)
          {
            if(f.slope>0)
              os<<"x-"<<abs(f.intercept)<<endl;
            else
              os<<"-x-"<<abs(f.intercept)<<endl;
          }
            else if(abs(f.slope)<epsilon1)
            os<<"-"<<abs(f.intercept)<<endl;
            else if (f.slope>0)
             os<<f.slope<<"x-"<<abs(f.intercept)<<endl;
            else
             os<<"-"<<abs(f.slope)<<"x-"<<abs(f.intercept)<<endl;
        }
        else
        {
          if(abs(abs(f.slope)-1)<epsilon1)
          {
            if(f.slope>0)
              os<<f.coef2<<"x*x+x-"<<abs(f.intercept)<<endl;
            else
              os<<f.coef2<<"x*x-x-"<<abs(f.intercept)<<endl;
          }
            else if(abs(f.slope)<epsilon1)
            os<<f.coef2<<"x*x-"<<abs(f.intercept)<<endl;
            else if (f.slope>0)
             os<<f.coef2<<"x*x+"<<f.slope<<"x-"<<abs(f.intercept)<<endl;
            else
             os<<f.coef2<<"x*x-"<<abs(f.slope)<<"x-"<<abs(f.intercept)<<endl;
        } 
    }
  else if(f.intercept>0)
  {
    {
      if(abs(abs(f.coef2)-1)<epsilon1)
      {
        if(f.coef2>0)
        {
          if(abs(abs(f.slope)-1)<epsilon1)
          {
            if(f.slope>0)
              os<<"x*x+x+"<<abs(f.intercept)<<endl;
            else
              os<<"x*x-x+"<<abs(f.intercept)<<endl;
          }
            else if(abs(f.slope)<epsilon1)
            os<<"x*x+"<<f.intercept<<endl;
            else if (f.slope>0)
             os<<"x*x+"<<f.slope<<"x+"<<abs(f.intercept)<<endl;
            else
             os<<"x*x-"<<abs(f.slope)<<"x+"<<abs(f.intercept)<<endl;
        }
        else
        {
          if(abs(abs(f.slope)-1)<epsilon1)
          {
            if(f.slope>0)
              os<<"-x*x+x+"<<abs(f.intercept)<<endl;
            else
              os<<"-x*x-x+"<<abs(f.intercept)<<endl;
          }
            else if(abs(f.slope)<epsilon1)
            os<<"-x*x+"<<abs(f.intercept)<<endl;
            else if (f.slope>0)
             os<<"-x*x+"<<f.slope<<"x+"<<abs(f.intercept)<<endl;
            else
             os<<"-x*x-"<<abs(f.slope)<<"x+"<<abs(f.intercept)<<endl;
          }
        }
        else if(abs(f.coef2)<epsilon1)
        {
          if(abs(abs(f.slope)-1)<epsilon1)
          {
            if(f.slope>0)
              os<<"x+"<<abs(f.intercept)<<endl;
            else
              os<<"-x+"<<abs(f.intercept)<<endl;
          }
            else if(abs(f.slope)<epsilon1)
            os<<abs(f.intercept)<<endl;
            else if (f.slope>0)
             os<<f.slope<<"x+"<<abs(f.intercept)<<endl;
            else
             os<<"-"<<abs(f.slope)<<"x+"<<abs(f.intercept)<<endl;
        }
        else
        {
          if(abs(abs(f.slope)-1)<epsilon1)
          {
            if(f.slope>0)
              os<<f.coef2<<"x*x+x+"<<abs(f.intercept)<<endl;
            else
              os<<f.coef2<<"x*x-x+"<<abs(f.intercept)<<endl;
          }
            else if(abs(f.slope)<epsilon1)
            os<<f.coef2<<"x*x+"<<abs(f.intercept)<<endl;
            else if (f.slope>0)
             os<<f.coef2<<"x*x+"<<f.slope<<"x+"<<abs(f.intercept)<<endl;
            else
             os<<f.coef2<<"x*x-"<<abs(f.slope)<<"x+"<<abs(f.intercept)<<endl;
        } 
    }
  }
  else
  {
      {
      if(abs(abs(f.coef2)-1)<epsilon1)
      {
        if(f.coef2>0)
        {
          if(abs(abs(f.slope)-1)<epsilon1)
          {
            if(f.slope>0)
              os<<"x*x+x"<<endl;
            else
              os<<"x*x-x"<<endl;
          }
            else if(abs(f.slope)<epsilon1)
            os<<"x*x"<<endl;
            else if (f.slope>0)
             os<<"x*x+"<<f.slope<<"x"<<endl;
            else
             os<<"x*x-"<<abs(f.slope)<<"x"<<endl;
        }
        else
        {
          if(abs(abs(f.slope)-1)<epsilon1)
          {
            if(f.slope>0)
              os<<"-x*x+x"<<endl;
            else
              os<<"-x*x-x"<<endl;
          }
            else if(abs(f.slope)<epsilon1)
            os<<"-x*x"<<endl;
            else if (f.slope>0)
             os<<"-x*x+"<<f.slope<<"x"<<endl;
            else
             os<<"-x*x-"<<abs(f.slope)<<"x"<<endl;
          }
        }
        else if(abs(f.coef2)<epsilon1)
        {
          if(abs(abs(f.slope)-1)<epsilon1)
          {
            if(f.slope>0)
              os<<"x"<<endl;
            else
              os<<"-x"<<endl;
          }
            else if(abs(f.slope)<epsilon1)
            os<<"0"<<endl;
            else if (f.slope>0)
             os<<f.slope<<"x"<<endl;
            else
             os<<"-"<<abs(f.slope)<<"x"<<endl;
        }
        else
        {
          if(abs(abs(f.slope)-1)<epsilon1)
          {
            if(f.slope>0)
              os<<f.coef2<<"x*x+x"<<endl;
            else
              os<<f.coef2<<"x*x-x"<<endl;
          }
            else if(abs(f.slope)<epsilon1)
            os<<f.coef2<<"x*x"<<endl;
            else if (f.slope>0)
             os<<f.coef2<<"x*x+"<<f.slope<<"x"<<endl;
            else
             os<<f.coef2<<"x*x-"<<abs(f.slope)<<"x"<<endl;
        } 
    }
  }
  return os;
}
    