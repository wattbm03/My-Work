 #include <stdio.h>

int main()
 {

printf("Hours worked: ");
double worked;
scanf("%lf", &worked);
printf("Hours worked are %lf \n", worked);

if(worked <= 40 && worked > 0 )
{
double s = 8.0*worked; 
printf("Salary is $ %lf", s);
}
else if (worked > 40)
{
  double sw =320+(worked-40)*12.0;
  printf("Salary is $ %lf", sw);
}
else
printf("Invaild input");

  return 0;
  
  }
