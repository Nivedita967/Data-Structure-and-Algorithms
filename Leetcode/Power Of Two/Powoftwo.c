bool isPowerOfTwo(int n)
{
    unsigned long int i=1; //Incase i*2 exceeds 2^31
    if(n>0) //Only positive numbers are required for this
    {
        while(i<=n)
        {
            if(i==n)
                return true;
            i *=2;
        }
    }
    return false;
}
