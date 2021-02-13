#include <bits/stdc++.h>

using namespace std;

    
int main()
{
    int n = 0, d = 0;
    scanf("%d %d", &n, &d);
    int arr[n];
    for (int i = 0; i < n; i ++)
    {
        cin>>arr[i];
    }
    for(int p = 0; p < d; p++)
    {
        int fst = arr[0];
        for (int c = 0; c < n - 1; c++)
        {
            arr[c] = arr[c + 1];
        }
        arr[n - 1] = fst;
    }
    for (int u = 0; u < n; u ++)
    {
        printf("%d ",arr[u]);
    }


    return 0;
}

