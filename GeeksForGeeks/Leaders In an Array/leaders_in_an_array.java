// Program to find all leaders in an array

// An element is leader if it is greater than all the elements to its right side of an array.
// And the rightmost element is always a leader.

void printLeaders(int arr[], int n)
{
    int maximum =  arr[n-1];
    int i;

    // Rightmost element is always leader
    printf("%d ", maximum);

    for(i = n-2; i >= 0; i--)
    {
        if(maximum < arr[i])
        {
           printf("%d ", arr[i]);
           maximum = arr[i];
        }
    }   
}