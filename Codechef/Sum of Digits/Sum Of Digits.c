//TODO: Print sum of digits of a given number

#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);              //TODO: reading number of tests


    for(int i=0;i<T;i++)
    {
        int n,sum=0;
        scanf("%d",&n);          //TODO: reading integers 

        while(n>0)
        {
            sum=sum+(n%10);
            n=n/10;
        }

        printf("%d\n",sum);       //TODO:displaying result
    }
}
