//TODO: To take a string from user and print a modified string

//TODO: Including header files
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char s[100];

    for (int i = 0; i != 46; i++)
    {
        scanf("%c", &s[i]);                    //TODO: Taking user input    
    }
    printf("Hello, World!\n");
    for (int p = 0; s[p] != '.'; p++)          //TODO: Printing modified string
    {
        printf("%c", s[p]);
    }
    printf(".\n");

    return 0;
}

