#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i,sum=0;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));     //dynamic memory allocation
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
        sum += (*(arr + i));                    // adding elements in the array one by one while taking i/p from the user
           }
    printf("%d",sum);                           //printing the sum
    return 0;
}
