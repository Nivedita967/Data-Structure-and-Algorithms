#include <stdio.h>


int main(void) 
{
    int n;
    scanf("%d",&n);
    int ans = 1;
    for (int i = 0; i < 10; i++)
    {
        if (n % (i + 1) == 0)
        {
            ans = i+1;
        }
    }
    printf("%d\n",ans);
    
}
