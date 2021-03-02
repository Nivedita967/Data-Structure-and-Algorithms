#include<bits/stdc++.h>
#define ll long long
using namespace std;
int32_t main()
{  ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    // taking input
    cin >> n;
    // applying loop
    for(int i = 10 ; i >0 ; i--)
    {
        // checking divisiblity
        if(n%i==0)  
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}