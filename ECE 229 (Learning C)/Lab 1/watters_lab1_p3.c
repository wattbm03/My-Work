#include <stdio.h>

int main() {
double time;
printf("Enter time in years \n");
scanf("%lf", &time);


if (5<=time )
{
printf("Has a 4.5 percent intrest rate.\n");
}
else if (4<=time && time<5)
{
 printf("Has a 4.0 percent intrest rate.\n");
}
else if (3<=time && time<4)
{
 printf("Has a 3.5 percent intrest rate.\n");
}
else if (2<=time && time<3)
{
 printf("Has a 2.5 percent intrest rate.\n");
}
else if (1<=time && time<2)
{
 printf("Has a 2.0 percent intrest rate.\n");
}
else if (0<=time && time<1)
{
 printf("Has a 1.5 percent intrest rate.\n");
}
else{
printf("Not a valid time.\n");
}
  return 0;
}