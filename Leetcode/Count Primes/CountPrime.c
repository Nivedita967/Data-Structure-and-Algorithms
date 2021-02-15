int countPrimes(int n)
{
    int count = 0, p=1;
    for(int i=2; i<n; i++)
    {
        for(int j=2; j*j<=i;j++) //taking j<= square root of i
        {
            if(i%j==0)
            {
                p=0;
                break; //No need to check any further
            }
        }
        if(p==1)
            count++;
        p=1;
    }
    return count;
}
