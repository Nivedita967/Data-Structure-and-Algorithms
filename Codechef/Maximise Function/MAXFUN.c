#include <stdio.h>
#include <limits.h>
int main(void) 
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long int n, sum, x; //using long long as int can't store this much large value
        long long int max=INT_MIN;
        long long int min=INT_MAX;
        scanf("%Ld", &n);
        for(int i=1; i<=n;i++)
        {
            scanf("%Ld", &x);
            if(x>max)
                max = x;
            
            if(x<min)
                min = x;
        }
        sum = max - min; //Using properties of modulus the solution will always be 2(max-min)
        sum *= 2;
        printf("%Ld\n", sum);
    }
	return 0;
}
