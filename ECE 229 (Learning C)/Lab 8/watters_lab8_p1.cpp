//Breeanna Watters
#include <iostream>
#define pi 3.14;
double cylvol(double r, double l);
using namespace std;


int main() {
  double r,l,v;
  cout << "Enter radius and length\n"<<endl;
  cin>>r>>l;
  
  v=cylvol(r, l);
cout<<"The voulme is "<<v<<" units cubed. \nThe radius was "<<r<<" units. \nThe length was "<<l<<" units."<<endl;
}
double cylvol(double r, double l){  
double v;
v=l*(r*r)*pi;
  return v;
}