#include <stdio.h>

int main(void)
{
    //variable declaration
    int t = 0;
    int a[1000];
    scanf("%d ", &t); //getting user input
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &a[i]); // getting the array
    }
    for (int p = 0; p < t; p++)
    {
        printf("%d ", a[t - p - 1]); // printing the array
    }
}
