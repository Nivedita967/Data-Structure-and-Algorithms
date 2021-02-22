//TODO: A program to find highest divisor

#include <stdio.h>


int main(void) 
{
    int n;
    scanf("%d",&n);                         //TODO: Taking user input
    int ans = 1;
    for (int i = 0; i < 10; i++)
    {
        if (n % (i + 1) == 0)              //TODO: Calculating answer
        {
            ans = i+1;
        }
    }
    printf("%d\n",ans);                     //TODO: Printing result

}
