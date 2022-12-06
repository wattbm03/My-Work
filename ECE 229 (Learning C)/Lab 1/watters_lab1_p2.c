#include <stdio.h>

int main() {

int month;
int day;
  printf("Input number of a month: \n");
scanf("%d", &month);
printf("Input day of the month: \n");
scanf("%d", &day);
printf("The month you chose %d \n", month);
printf("The day you chose %d \n", day);

if (!(1<=month    && month<=12))
{
printf("Not a valid month.\n");
}
else if (!(1<=day && day<=31))
{
  printf("Not a valid day.\n");
}
else
printf("The month is %d and the day is %d \n", month, day );


  return 0;
}
