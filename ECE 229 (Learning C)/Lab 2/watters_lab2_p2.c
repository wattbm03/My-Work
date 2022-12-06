#include <stdio.h>

int main()
{
int amount=5000;
double iRate=.03;
int year=1;
double total=amount;

while(year<8)
{
total= (iRate*total)+total;
printf("The amount in the acount after year %d is %.2f\n", year, total);
  year++;
}

  return 0;
}