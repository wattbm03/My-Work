// Breeanna Watters
#include<iostream>
#include<cmath>
using namespace std;
 
class Complex
{
    private :
        double real;
        double imag;
      
    public :
      Complex(double r = 0, double i  = 0);  
      void print();
      void real_1();
      void imag_1();
      double mag(double r, double i);
      double add(double r, double i, double r2, double i2);
      double sub(double r, double i, double r2, double i2);

};

Complex :: Complex(double r, double i)
{
  real=r;
  imag=i;
}
 void Complex :: print()
{
      cout << "The complex number is    "<< real << " + "
        << imag << "j"<< endl;
}

 void Complex :: real_1()
 {
    cout << "The real number is    "<< real << endl;
 }

void Complex :: imag_1()
 {
  cout << "The imaginary number is    "<<  imag << "j"<< endl;
 }
 double Complex :: mag(double r, double i)
 {
   double tude, result;
   tude=(r*r)+(i*i);
   result=sqrt(tude);
   return result;
 }

double Complex :: add(double r, double i, double r2, double i2)
{
  double re, im;
  re=r+r2;
  im=i+i2;
  cout<<"The adding of the complex numbers is: "<<re<< " + "<< im << "j"<< endl;
return 0;
}

double Complex :: sub(double r, double i, double r2, double i2)
{
  double re, im;
  re=r-r2;
  im=i-i2;
  cout<<"The Subtracting of the complex numbers is: "<<re<< " + "<< im << "j"<< endl;

  return 0;
}


int main()
{
    double r, i,r2,i2, T, To, diff;
    cout <<"Input the real number then the imaginary one:\n";
    cin>>r>>i;
  
    Complex t1(r, i);
    cout <<"Input the real number then the imaginary one, for the second one:\n";
    cin>>r2>>i2;
    Complex t2(r2, i2);
    cout<<"Now for complex number 1"<<endl;
    t1.print();
    t1.real_1();
    t1.imag_1();
    T=t1.mag(r,i);
    cout<<"Magnitude "<<T<<endl<<endl<<endl<<"Now for complex number 2"<<endl;


    t2.print();
    t2.real_1();
    t2.imag_1();
    To=t2.mag(r2,i2);
    cout<<"Magnitude "<<To<<endl<<endl<<"Now for adding and subtracing the numbers from the first complex to the second one"<<endl<<endl<<endl;
    t1.add(r,i,r2,i2);
    t1.sub(r,i,r2,i2);
   
  
    return 0;}
