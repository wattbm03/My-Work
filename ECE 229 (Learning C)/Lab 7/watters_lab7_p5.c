//Breeanna Watters
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1000
int  isEmpty(const char *str);
void removeEmptyLines(FILE *fptr1, FILE *fptr2);
void printFile(FILE *fptr);

int main()
{FILE *fptr1, *fptr2;
    char fname[20], str;
   
    printf("Enter file: ");
    scanf("%s", fname);
    fptr1  = fopen(fname, "r");
    fptr2 = fopen("nospaces.txt", "w+");
    if (fptr1 == NULL || fptr2 == NULL)
    {
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    rewind(fptr1);
    removeEmptyLines(fptr1, fptr2);

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
void printFile(FILE *fptr)
{
    char ch;

    while((ch = fgetc(fptr)) != EOF)
        putchar(ch);
}
int isEmpty(const char *str)
{
    char ch;

    do
    {
        ch = *(str++);
        if(ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != '\0')
            return 0;

    } while (ch != '\0');

    return 1;
}
void removeEmptyLines(FILE *fptr1, FILE *fptr2)
{
    char buffer[BUFFER_SIZE];

    while ((fgets(buffer, BUFFER_SIZE, fptr1)) != NULL)
    {
        if(!isEmpty(buffer))
            fputs(buffer, fptr2);
    }
}
