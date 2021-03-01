/*
This program is going to print the result as per the below pattern.
Sample Input: 
5
Sample Output :
5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5

*/

#include <stdio.h>

int main() 
{

    int n; // Declaring the variable
    scanf("%d", &n); //Initialzing the user input to the declared variable.
    int len = n*2 - 1; //Assigning the length
    for(int i=0;i<len;i++){ // Using the loop for the column
        for(int j=0;j<len;j++){ //using the loop for the row
            int min = i < j ? i : j; // Assigning the min value
            min = min < len-i ? min : len-i-1; //Applying the logic
            min = min < len-j-1 ? min : len-j-1; //Applying the logic
            printf("%d ", n-min); // Printing the value.
        }
        printf("\n");
    }
    return 0;
}


