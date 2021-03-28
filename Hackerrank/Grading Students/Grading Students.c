#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);                            // Taking number of grades provided
    for(int a0 = 0; a0 < n; a0++)
    {
        int grade; 
        scanf("%d",&grade);                    // Taking grade
        if(grade<38 || (grade%5)<=2)           // Printing grade after updating it
            printf("%d\n",grade);
        else
            printf("%d\n",grade+(5-grade%5));
    }
    return 0;
}
