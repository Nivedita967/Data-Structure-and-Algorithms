#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int N, output;
        long long int K, D, A, Asum=0; //taking long long due to constraints
        scanf("%d %Ld %Ld", &N, &K, &D);
        while(N--)
        {
            scanf("%Ld", &A);
            Asum += A; //getting total number of problems
        }
        output = Asum/K; //checking how many can be made
        if(output<=D)
            printf("%d\n", output);
        else
            printf("%d\n", D); //If number of days required are less then print the days count
    }
	return 0;
}
