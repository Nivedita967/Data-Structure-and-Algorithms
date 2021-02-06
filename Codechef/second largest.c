#include <stdio.h>

int great(int n1,int n2)
{
    if(n1>n2)
    {
        return n1;
    }
    else
    {
        return n2;
    }
}

int small(int n3,int n4)
{
    if(n3 < n4)
    {
        return n3;
    }
    else
    {
        return n4;
    }
}


int main(void)
{
    int t;
    scanf("%d",&t);
    int a=0,b=0,c=0;
    for(int p=0;p<t;p++)
    {
        scanf("%d %d %d",&a,&b,&c);

    int d = great(a,b);
    int e = great(b,c);
    int f = great(e,d);

    int g = small(a,b);
    int h = small(b,c);
    int i = small(g,h);
    int ans = a+b+c-f-i;
    printf("%d",ans);
    printf("\n");
    }
}
