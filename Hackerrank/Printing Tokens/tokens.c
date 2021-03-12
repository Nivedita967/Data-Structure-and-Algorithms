#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s; //declaring char pointer
    s = malloc(1024 * sizeof(char)); //Allocating memory dynamically 
    gets(s); //Taking inputs from user as string 
    s = realloc(s, strlen(s) + 1); //Reallocating memory as per the length of the string.
    //Write your logic to print the tokens of the sentence here.
    for(int i=0; s[i]!='\0'; i++)
    {
        printf("%c", s[i]); //Printing the char one by one

        if(s[i]==' ') //Checking for space in betweeen sentence
        {
            printf("\n"); // If so printing line gap on it.
        }
    }
    return 0;
}

