#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char c;
    char a[100],b[100];
    scanf("%c",&c); //Taking Input
    scanf("\n");
    scanf("%[^\n]%*c",a);
    scanf("\n");
    scanf("%[^\n]%*c",b);
    printf("%c",c);  //Displaying Desired output
    printf("\n");
    puts(a);
    printf("%s",b);
     
    return 0;
}

