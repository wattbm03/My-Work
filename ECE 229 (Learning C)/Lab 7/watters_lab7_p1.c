//Breeanna Watters
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fptr1, *fptr2;
	char str;

	fptr1=fopen("employee.dat", "r");
	if(fptr1==NULL)
	{
		printf("ERROR");
		exit(1);
	}
	
	fptr2=fopen("employee.bak", "w+");
	if(fptr2==NULL)
	{
		printf("ERROR");
		fclose(fptr1);
		exit(2);
	}
	while(1)
	{
		str=fgetc(fptr1);
		if(str==EOF)
		{
			break;
		}
		else
		{
			fputc(str, fptr2);
		}
	}

	fclose(fptr1);
	fclose(fptr2);
  return 0;
}