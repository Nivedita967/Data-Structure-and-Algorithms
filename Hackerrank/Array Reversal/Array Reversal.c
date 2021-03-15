#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));  // dynamic memory allocation
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);                 //taking input
    }
for(i = num-1; i>-1; i--)
        printf("%d ", *(arr + i));           //printing array in reverse order
    return 0;
}
