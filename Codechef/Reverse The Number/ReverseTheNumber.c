#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d",&t);
    int mul;
    for(int i=0;i<t;i++)
    {   
        int num = 0;
        int num2=0;
        scanf("%d", &num);
        while (num > 0)
        {
            num2 = num2 * 10 + (num % 10);
            num = (num - (num % 10)) / 10;
        }
        printf("%d\n", num2);
    }
}
