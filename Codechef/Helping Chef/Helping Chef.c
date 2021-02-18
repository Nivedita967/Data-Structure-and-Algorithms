//TODO: Display string if input is less than 10

#include <stdio.h>


int main(void) 
{
    int t;
    scanf("%d",&t);             //TODO:Get never of test cases
    for(int i = 0; i < t;i++)
    {   int n;
        scanf("%d", &n);        //TODO:Get input
        if(n < 10)
        {
            printf("Thanks for helping Chef!\n");  

        }
        else
        {
            printf("-1\n");      //TODO: Printing results
        }

    }
}
