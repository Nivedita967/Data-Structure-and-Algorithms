#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char *s; //Declaring char type pointer
    s = malloc(1024 * sizeof(char)); //Allocating memory dynamically
    scanf("%s", s); //taking input in the format of string
    s = realloc(s, strlen(s) + 1); //Reallocating memory as per the length of the string.
    int len = strlen(s); //Assigning length of the string into len variable. 
	int i; 
    int arr[10]; // Declaring array
    for(i = 0; i < 10; i++) 
        arr[i] = 0; // Initially making it as zero's 
    for(i = 0; i < len; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            arr[(int)(s[i] - '0')]++; //Incrementing array value id condtion statifies.
        }
    }
    for(i = 0; i < 10; i++)
        printf("%d ", arr[i]); //Printing the values.
    printf("\n");
    free(s); // Deleting the memory. 
    return 0;
}

