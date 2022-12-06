#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{int guess;
 
   srand(time(NULL));
    guess= 1+ rand() % (100);
    printf("I have a number between 1 and 100. Can you guess my number?\n");
    int i;
  for(i=0; i>=0; i++)
  {
    int num;
    printf("Please pick a number:");
    scanf("%d", &num);
    if(num==guess)
      {
        printf("Excellent!You Guessed the number!");
      break;
      }
    else if(num<guess)
     {printf("Too Low. Try Again.\n");}

     else if(num>guess)
    {printf("Too High. Try Again.\n");}
  }
  return 0;
}

