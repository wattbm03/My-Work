//Breeanna Watters
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define one 128 
#define two 128 

int main() 
{
    char line[two][one];
	char fname[20];
    FILE *fptr = NULL; 
    int i = 0;
    int tot = 0;
 printf(" Input the file name to be opened : ");
	scanf("%s",fname);

    fptr = fopen(fname, "r");

   

    while(fgets(line[i], one, fptr)) 
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
	printf("\n The content of the file are : \n");    
    for(i = 0; i < tot; ++i)
    {
        printf("Line %d says ---- %s\n",i+1, line[i]);
    }
    printf("\n");
	
    return 0;
}