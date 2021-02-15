#include <stdio.h>

int main(void)
{
    int t; //test cases
    scanf("%d", &t);
    while(t--)
    {
        int n, d, a, Tr=0, Tnr=0, out; //using same question variable and Tr = Total at risk and Tnr = Total not at risk
        scanf("%d %d", &n, &d);
        while(n--)
        {
            scanf("%d", &a);
            if(a>= 80 || a<= 9)
                Tr++;
            else
                Tnr++;
        }
        if(Tr%d==0) 
            out = Tr/d;
        else
            out = (Tr/d) +1; //If it isn't divisible then only one extra day is need for ex in case of 24 5, 4 days for 20 peoples and 1 day for remaining 4 so total of 5 days
        if(Tnr%d==0)
            out += Tnr/d;
        else
            out += (Tnr/d) +1;
        printf("%d\n", out);
    }
	return 0;
}
