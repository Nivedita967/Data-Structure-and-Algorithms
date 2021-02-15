#include <stdio.h>

int main(void)
{
    int t; //test cases
    scanf("%d", &t);
    while(t--)
    {
        int n,a,sum=0;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &a);
            sum += a; //taking sum of all
        }
        if(sum >=0) //if sum is positive or 0 it's YES as we can do operation over it
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
