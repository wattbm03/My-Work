#include <stdio.h>

int main()
{
    int index; 
    int lower; 
    int upper; 
    int square; 
    int total; 
 

    printf("Enter lower and upper integer limits: ");

    while (scanf("%d %d", &lower, &upper) == 2)
    {
    while (lower < upper)
    {
      total = 0;
      for (index = lower; index <= upper; index++)
      {
        square = index*index ;
        total += square;
      }

      int low=lower*lower;
      int high=upper*upper;


        printf("The sums of the squares from %d to %d is %d \n", low, high, total);
        printf("Enter the next set of limits: \n");
        scanf("%d %d", &lower, &upper);

    }
    printf("Done");
    break;
}

    return 0;
}