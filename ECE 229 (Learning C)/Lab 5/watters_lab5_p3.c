//Breeanna Watters
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define maxlength 81
void reverse(char*);
int main()
{
  printf("Enter a string: ");
 char str[maxlength];
 fgets(str, sizeof(str), stdin);
	int size = strlen(str);
	reverse(str);
	 printf("This is s1 after: %s\n", str);
	return 0;
}
void reverse(char* str)
{
	char *start = str;
	char *end = start+strlen(str)-1;

	while(start<end)
	{
		char mid = *end;
		*end = *start;
		*start=mid;
		start++;
		end--;
	}}