//issue #25
int xorOperation(int n, int start)
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum ^= (start + 2*i);
    }
    return sum;
}
