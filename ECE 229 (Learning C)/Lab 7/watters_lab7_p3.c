//Breeanna Watters
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define one 128 
#define two 128 
struct cars
{
	int carnum;
	int miles;
	int gals;
};
int main(){
  FILE *fptr1; 
   char fname[20];
   char line[two][one];
   int totalmiles = 0;
   int totalgals = 0;
   int i = 0,j=0;
   int tot = 0;
  printf(" Input the file name to be opened : ");
  scanf("%s",fname);
  fptr1 = fopen(fname, "r");
    if(fptr1==NULL){
		  printf("ERROR");
		  exit(1);
    }
    while(fgets(line[i], one, fptr1)) 
	  {
      line[i][strlen(line[i]) - 1] = '\0';
      i++;
    }
    tot = i; 
  
    while(fptr1 != NULL)
    {
    int car[tot-1][3];
    for(i=0; i<tot-1; i++)
      {for(j=0;j<3; j++){
       fscanf(fptr1, "%d", &car[i][j]); }
      totalmiles += car[i][1];
      totalgals += car[i][2]; }
	  
    }
printf("Total mile driven by all cars is %d ", totalmiles);
printf("Total gallons used by all cars is %d ", totalgals);
printf("Average miles per gallons by all cars is %lf ", (double)totalmiles/totalgals);
      return 0;
      }
