#include <stdio.h>

int main(void) 
{
	int t;
    scanf("%d", &t);
    while(t--)
    {
        int d,c;
        scanf("%d %d", &d, &c);
        int d1=0, d2=0;
        for(int i=1; i<=3; i++)
        {
            int a;
            scanf("%d", &a);
            d1 += a;
        }
        for(int i=1; i<=3; i++)
        {
            int a;
            scanf("%d", &a);
            d2 += a;
        }
        /*
        If cost is less than 150 there is no free delivery
        Even with the coupon, so it's a overhead in that
        */
        int withc=c, noc=d;
        if(d1<150)
            {
                withc += d+d1;
            }
        else
            withc += d1;
        if(d2<150)
            {
                withc += d2+d;
            }
        else
            withc += d2;
        noc= d1+d2+d+d;
        if(withc<noc)
            printf("YES\n");
        else
            printf("NO\n");
    }
	return 0;
}
