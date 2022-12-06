//Breeanna Watters
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int findmax();

int main(void) {
  findmax();
  return 0;
}

int findmax() 
{ int n=10;
  int m=15;
   double find[n][m];
  int i,j, total, max, maxr, maxc;
  max =0;
   srand(time(NULL));
  for( i=0;i<n;i++)
  { for(j=0;j<m;j++){
    
   find[i][j]=0+rand()%100; 
   }
  }
    max=find[0][0];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(max<find[i][j])
            {
                max=find[i][j];
                 maxr=i;  
                 maxc=j;   
            }

            
        }
    }

    printf("Max element in find is %d in location find[%d][%d]\n",  max, maxc, maxr);
}



