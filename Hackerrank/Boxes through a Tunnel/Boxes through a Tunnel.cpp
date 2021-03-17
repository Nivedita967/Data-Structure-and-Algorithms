#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int32_t main()
{
    // input for number of test Cases
int t;
cin >> t;
while(t>0)
{
    // Intializing the length,width,height variables
    int len , wid , height;
    // Input the length,width,height variables
    cin >> len >> wid >> height;
    // if height greater than equal to 41 as mentiones we need to do nothing simply return
    if(height>=41)
    {
        // Output nothing just return to the next test Case
        t--;
    }
    // otherwise we need to find the volume which is given below
    else
    {
        cout << len*wid*height << endl;
        t--;
    }
}
return 0;
}