// NOTE: have used my own I/O so to use this code you need to clear the entire hackerrank existing code




#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    long int n, left=0, right=0, i, j, a[100000], out, max=0;
    
    scanf("%ld", &n); //take input
    for(i=0;i<n;i++) //take array input
        {
        scanf("%ld", &a[i]);
    } 
    for(i=n-1;i>=1;i--) //iterate through the array
        {
        if(a[i]<a[i+1]&&a[i]<a[i-1]) //checking for condition given in question
            {
            max=i*(i+2);
            break;
        }
    }
    printf("%ld", max); //printing result
    return 0;
}