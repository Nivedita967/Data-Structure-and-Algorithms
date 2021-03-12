#include<bits/stdc++.h>
#define ll long long
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll k;
        // Since Ai values are given such that so we need to take long long here. 
        ll*arr=new ll[10];
        // Taking Input by using loop
        for(int i = 0 ; i < 10 ; i++)
        {
            cin >> arr[i];
        }
        cin >> k;
        int i = 1;
        while(k >= 0)
        {
           k =  k - arr[10-i];
        //    cout << "k" << " " << k << endl;
           i++;
        }
        cout << 10-i+2 << endl;

    }
    return 0;
}
