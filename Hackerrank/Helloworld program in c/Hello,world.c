#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char s[100];

    for (int i = 0; i != 46; i++)
    {
        scanf("%c", &s[i]);
    }
    printf("Hello, World!\n");
    for (int p = 0; s[p] != '.'; p++)
    {
        printf("%c", s[p]);
    }
    printf(".\n");

    return 0;
}