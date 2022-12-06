#include <stdio.h>
int findparty(num){
if(num % 2)
printf("The number is ODD.\n");
else
printf("The number is EVEN.\n");
return 0;
}

int main(void) {
int num;
printf("Enter a number: \n");
scanf("%d", &num);
  findparty(num);
  return 0;
}
