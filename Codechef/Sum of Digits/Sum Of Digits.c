#include<stdio.h>


int main()
{
    int T;
    scanf("%d",&T);//reading number of tests


    for(int i=0;i<T;i++)
    {
        int n,sum=0;
        scanf("%d",&n);//reading integers 
        
        while(n>0)
        {
            sum=sum+(n%10);
            n=n/10;
        }
        
        printf("%d\n",sum);//displaying result
    }
}

