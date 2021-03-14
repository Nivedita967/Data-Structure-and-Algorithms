#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int32_t main()
{
int t;
cin >> t;
while(t>0)
{
    int len , wid , height;
    cin >> len >> wid >> height;
    if(height>=41)
    {
        t--;
    }
    else
    {
        cout << len*wid*height << endl;
        t--;
    }
}
return 0;
}