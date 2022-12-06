#include <stdio.h>

int main()
 {
    char choice;
    char row;
    char spaces;
    char ascending;
    char descending;

    printf("Insert uppercase letter: ");
        scanf("%c", &choice);

    for(row = 'A'; row <= choice; row++)
     {

        for(spaces = choice; spaces > row; spaces--)
            printf(" ");


        for(ascending = 'A'; ascending < row; ascending++)
            printf("%c", ascending);   


        for(descending = ascending; descending >= 'A'; descending--)
            printf("%c", descending);

        printf("\n");
    }

    return 0;

}
