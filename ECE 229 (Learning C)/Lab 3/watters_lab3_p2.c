#include <stdio.h>
#include <math.h>
double polyTwo(double a, double b, double c, double x)
{return a*(x*x)+(b*x)+c;} 

int main()
{
  double a,b,c,x,y;


  printf("Enter a values for a, b, c and x:\n");
  scanf("%lf %lf %lf %lf", &a, &b, &c, &x);

 y=polyTwo(a, b, c, x);

  printf("y = %lf", y);
  
  return 0;
}

