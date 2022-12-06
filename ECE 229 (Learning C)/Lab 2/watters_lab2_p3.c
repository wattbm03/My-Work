#include <stdio.h>

int main()
 {
  int year=1;
  double daphne=100.00;
  double deirdre=100.00;
  double daphneTotal;
  double deirdreTotal=100.00;
  double ci=0.05;
  double si=0.10;
  do{
    printf("\n Year is %d", year);
    daphneTotal=(daphne*year*si)+daphne;
    printf("\n Daphne invests %.2f", daphneTotal);
    deirdreTotal=(deirdreTotal*ci)+deirdreTotal;
     printf("\n Deirdre invests %.2f", deirdreTotal);
    year++;
  }
  while(daphneTotal>deirdreTotal);
  printf("\n\n Deirdre's investment exceded Daphne's investment at year %d ", year-1);

  return 0;
}