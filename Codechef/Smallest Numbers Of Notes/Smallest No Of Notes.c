#include <stdio.h>


int main(void) 
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t;i++)
    {
        int n = 0;
        scanf("%d",&n);
        int count = 0;
        while (n >= 100)
        {
            n -= 100;
            count++;
        }
        while (n >= 50)
        {
            n -= 50;
            count++;
        }
        while (n >= 10)
        {
            n -= 10;
            count++;
        }while (n >= 5)
        {
            n -= 5;
            count++;
        }
        while (n >= 2)
        {
            n -= 2;
            count++;
        }
        while (n >= 1)
        {
            n -= 1;
            count++;
        }
        printf("%d\n",count);
    }
}
