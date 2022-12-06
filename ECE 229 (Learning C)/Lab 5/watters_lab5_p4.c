//Breeanna Watters
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<ctype.h>

int main(void)
{ printf("Enter a qoute or phrase: ");
  int n=0,count[26]={0};
  char c;
  do
  { c=getchar();
    if(isalpha(c))
    {
      char cap=toupper(c);
      ++count[cap -'A'];
    }
    ++n;
  }
  while(c!='\n');
  int total=0,different=0;
  for(int n=0;n<26;++n)
  {
    if(count[n]){
      ++different;
      total+=count[n];
    }
  }
  double frequency;
  frequency=(count[4]/(double)total);
  printf("\nTotal %d.\nFrequency for e is %lf.\n",total,frequency);
  return 0;
}
