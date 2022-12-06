//Breeanna Watters
#include<stdio.h>

int main()
{
    int b;
    
    char fname[20];
    FILE *P;
    FILE *T;
    printf(" Input the file name to be opened : ");
	scanf("%s",fname);
    P=fopen(fname,"r");
    T=fopen("./duplicate.txt","w");
    for(;(b=getc(P))!=EOF;)
    {
        if(b==32)
        {
            fputc(b,T);
            me:
            b=getc(P);
            if(b==32)
            goto me;
        }
        fputc(b,T);
    }
}