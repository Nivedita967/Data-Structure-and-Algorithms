/*
It follows fibonaanic series
*/
int climbStairs(int n)
{
    int s0=0, s1=1, s2;
    while(n--)
    {
        s2 = s1 + s0;
        s0= s1;
        s1= s2;
    }
    return s2;
}
