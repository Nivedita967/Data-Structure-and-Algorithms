#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,k;
    cin>>n>>k;
    
    int a,b,c=0,d=0,e=0;
    
    for (a=1;a<n;a++)
    {
        for (b=n;b>a;b--)
        {
            if ((a&b)<k && (a&b)>c) {c = a&b;}
            if ((a|b)<k && (a|b)>d) {d = a|b;}
            if ((a^b)<k && (a^b)>e) {e = a^b;}
        }
    }

    cout<<c<<d<<e;
    return 0;
}