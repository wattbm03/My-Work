//Breeanna Watters
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main() {
  double grades[4][4];
  int i,j;
  srand(time(NULL));
  for( i=0;i<4;i++)
  { for(j=0;j<3;j++)
    grades[i][j]=40+rand()%60;
   
  }
for( i=0;i<4;i++)
  {grades[i][3]=.5*grades[i][0]+.2*grades[i][1]+.3*grades[i][2];}

printf("           Lab        Quiz       Exam       Final\n");

for( i=0;i<4;i++)
  { 
  printf("student %d  %lf  %lf  %lf  %lf\n", i+1, grades[i][1], grades[i][1], grades[i][2], grades[i][3]);}

  return 0;
}
