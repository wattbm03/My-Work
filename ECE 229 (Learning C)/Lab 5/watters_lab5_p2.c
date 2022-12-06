//Breeanna Watters
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
double arr[7]={12.99, 18.69, 11.44, 13.75, 9.59, 15.29, 17.69};
double *min, *jmin;
int t,i;

min = arr;
jmin=arr;
for(i=0; i<7; i++)
{
  if(*jmin > (*(min+i)))
 *jmin= (*(min+i));

}
for(i=0; i<7; i++)
if(*jmin==*(min+i))
t=i;
printf("The min value is %lf and the index is %d ",*jmin, t );
  return 0;
}

