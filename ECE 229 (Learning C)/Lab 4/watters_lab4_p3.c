//Breeanna Watters
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main() {
double raw[10], sorted[10], total;
int i,j,max,min;

for(i=0;i<10;i++)
{printf("Enter a different number: ");
scanf("%lf", &raw[i]);}

for( i=0;i<10;i++)
{printf("%lf at raw[%d]\n", raw[i],i);
total += raw[i];
}

for(i=0;i<10;i++)
{   min=total;
  if(i!=0)
  max=sorted[i-1];
  for(j=0;j<10;j++)
  {if(i==0)
     { if(raw[j]<min)
        min=raw[j];}

    if(i!=0)
    {if(raw[j]<min && raw[j]>max)
      min=raw[j];
      }    
  
  }

sorted[i]=min;


}


printf("Min to max\n");
for( i=0;i<10;i++)
printf("%lf at sorted[%d]\n", sorted[i],i);


  return 0;
}
