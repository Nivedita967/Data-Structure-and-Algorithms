#include <bits/stdc++.h>
using namespace std;
 
int main() {

    //code snippet for fast i/o
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    
    int n,k;
    cin>>n>>k;
    
    int a,b,c=0,d=0,e=0; //c d and e will store and or and xor results repectively.
    
    for (a=1;a<n;a++)  //iterate from start
    {
        for (b=n;b>a;b--) //iterate from end
        {
            if ((a&b)<k && (a&b)>c) {c = a&b;} 
            if ((a|b)<k && (a|b)>d) {d = a|b;}
            if ((a^b)<k && (a^b)>e) {e = a^b;}
        }
    }

    cout<<c<<d<<e;
    return 0;
}