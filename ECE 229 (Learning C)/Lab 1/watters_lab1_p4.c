#include <stdio.h>

int main() {

int code;
printf("Enter code: \n");
scanf("%d", &code);
printf("Code chosen %d \n", code);

switch(code)
{
case 1:
 printf("Manufacted by 3M Corporation");
  break;
case 2:
  printf("Manufacted by West Digtial Corporation");
  break;

case 3:
  printf("Manufacted by Seagate Corporation");
  break;

case 4:
  printf("Manufacted by Verbatim Corporation");
  break;
}

  return 0;
}