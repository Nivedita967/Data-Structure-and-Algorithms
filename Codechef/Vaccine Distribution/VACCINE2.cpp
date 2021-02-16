#include <bits/stdc++.h>
#define ll long long
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define vec  vector<ll>

 
using namespace std;

ll Function()
{
    double n,d,maxi=INT_MIN,mini=INT_MAX,count_r=0,count_nr=0; //Initializing Variables
    cin>>n>>d;
    vector<double> vect(n);
    for(ll i=0;i<n;i++)
    {
        cin>>vect[i];         // Taking input as elements of vector.
    }
    for(auto k:vect)
    {
        if(k<=9 or k>=80)
        {
            count_r++;           // Incrementing count_r to the desired value on the basis of if and else conditions
        }
        else
        {
            count_nr++;
        }
    }
    
    ll   x1 = ceil(count_r/d);     // Taking ceil value of the floating values
    ll   x2 = ceil(count_nr/d);

    return (x1+x2);  //Returning Output
}
 
int main() // Main Function
{   
 
	BOOST;
    ll res,t;
    cin>>t;
    while(t--)
    {
    res = Function();
    cout<<res<<"\n";    //Printing Output
    }
	return 0;
	
}
