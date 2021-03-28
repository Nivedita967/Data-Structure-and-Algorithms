//Time Complexity O(n^2)
int divisibleSumPairs(int n, int k, int ar_count, int* ar) 
{
    int count = 0;
    for(int i=0; i<ar_count; i++)
    {
        for(int j=i+1;j<ar_count; j++)
        {
            if((ar[i]+ar[j])%k==0) //Checking the condition
                count++;
        }
    }
    return count;
}
