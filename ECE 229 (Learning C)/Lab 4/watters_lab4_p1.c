//Breeanna Watters
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
  double grade[30], deviation[30], total, totalD;
  srand(time(NULL));
  int i;
  for (i=0; i<30;i++)
  {
    grade[i]=50+rand()%51;
   total += grade[i];
   }
  double average=total/30;
  for(i=0; i<30 ;i++)
  {
   deviation[i] = grade[i]- average;
    
    printf("grade %lf and deviation %lf \n", grade[i], deviation[i]);
  }
  for(i=0; i<30; i++)
   {
    totalD += deviation[i]* deviation[i];

   }
  double variance= totalD/30; 
  printf("variance is %lf\n", variance);

  return 0;
}