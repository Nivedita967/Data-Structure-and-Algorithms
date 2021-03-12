#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    // These are The Inbuild Functions Used to set the number of values upto any no. of decimal Points which are rounded off accordingly
    cout << fixed;
    cout << setprecision(1);
    int a,b;
    // Taing Input
    cin >> a >>b;  
    // Getting output
    cout << a+b << " " << a-b << endl;
    float c,d;
    cin >> c >> d;
    cout << c+d <<" " << c-d << " " ;
    return 0;
}
