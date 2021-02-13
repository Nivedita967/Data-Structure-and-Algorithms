//TODO: Shift a given integer array to a given number of steps

#include <bits/stdc++.h>

using namespace std;


int main()
{
    //TODO: Reading user input
    int n = 0, d = 0;
    scanf("%d %d", &n, &d);
    int arr[n];
    
    //TODO: Reading the given array
    for (int i = 0; i < n; i ++)
    {
        cin>>arr[i];
    }
    
    //TODO: Shifting the array
    for(int p = 0; p < d; p++)
    {
        int fst = arr[0];
        for (int c = 0; c < n - 1; c++)
        {
            arr[c] = arr[c + 1];
        }
        arr[n - 1] = fst;
    }
    
    //TODO: Printing the result array
    for (int u = 0; u < n; u ++)
    {
        printf("%d ",arr[u]);
    }


    return 0;
}
