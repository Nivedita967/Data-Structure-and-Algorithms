#include <stdio.h>

int main(void) 
{
    int t; //test case
    scanf("%d", &t);
    while(t--)
    {
        int n, sum=0, use=0; //sum is distance travel and use is gas used
        scanf("%d", &n);
        int f[n];
        for(int i=0; i<n; i++)
            scanf("%d", &f[i]); //getting all the inputs here so that it doesn't conflict with next test case in case of loop break
        for(int i=0; i<n; i++)
        {
            use += f[i];
            sum += f[i];
            if(use==0) //If gas is empty the loop breaks
                break;
            use--; //after every turn 1L gas is being used
        }
        printf("%d\n", sum);
    }
	return 0;
}
