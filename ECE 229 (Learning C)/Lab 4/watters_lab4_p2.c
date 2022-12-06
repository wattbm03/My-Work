//Breeanna Watters
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
double extend(double p[],double q[],double a[]);



int main() {
double a[10];
double price[10]={10.64,14.89,15.21,74.21,23.8,61.26,92.37,12.73,2.99,58.98};
double quantity[10]={4,8,17,2,94,61,20,78,55,41};
double amount[10];
extend(price, quantity, amount); 

  
  for(int i=0;i<10;i++)
  printf("amount[%d]is %f\n", i, amount[i]);

  return 0;
}


double extend(double p[10],double q[10],double a[10])
{

  for(int i=0;i<10;i++){
  a[i]=p[i]*q[i];}


  return 0;
}
