#include <stdio.h>
int liquid(int cup)
{
int gallon, pint, quart;
gallon=cup/16;
quart=cup%16/4;
pint=cup%4/2;
cup=cup%2;
printf("Gallons=%d \nQuarts=%d\nPints=%d\nCups=%d", gallon, quart, pint, cup);
}

int main()
{

int cup;
printf(" Enter number of cups:");
scanf("%d", &cup);
 liquid(cup);

  return 0;
}

