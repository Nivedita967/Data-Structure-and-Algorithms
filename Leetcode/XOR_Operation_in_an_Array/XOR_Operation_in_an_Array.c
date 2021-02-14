int xorOperation(int n, int start)
{
    int sum=0;
    for(int i=0; i<n; i++) //Loop for taking gaps
    {
        sum ^= (start + 2*i); // Taking XOR of the next number which is an AP of 2 from start and adding it to previous sum
    }
    return sum;
}
