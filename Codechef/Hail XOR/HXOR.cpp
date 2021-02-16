// Problem Link - https://www.codechef.com/DEC20B/problems/HXOR


#include <bits/stdc++.h> 
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define ll long long

 

using namespace std;



void Function()
{
    ll n,x,maxi=INT_MIN,mini=INT_MAX; //Initializing variables
    cin>>n>>x;
    vector<ll>vect(n);
    for(ll i=0;i<n;i++)
    {
        cin>>vect[i];   //Taking Input
    }
    ll i=0;
    ll two = 2;
    ll check;
    for(ll j=x;j>0 and i<n-1;j--)
    {
        ll flag = 0;
        ll p = log(vect[i])/log(2);
        ll r = pow(two,p);
        vect[i] = vect[i]^r;
        for(ll h = i+1;h<n;h++)
        {
            if((vect[h]^r)<vect[h])
            {
                vect[h] ^= r;        //Logic of th problem
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            vect[n-1] ^= r;
        }
        
        while(vect[i]<=0)
        {
            i++;
        }
        check = j+1;
    }
      if(check>0)
        {
            if(n<3 and check%2>0)
            {
                vect[n-1]^=1;
                vect[n-2]^=1;
            }
        }
    for(auto i:vect)
    {
        cout<<i<<" ";    //Displaying Output
    }
}
 
int main()
{   
 
	BOOST;
	ll t;
	cin>>t;
	while(t--)
	{
    Function();
	}
	return 0;
	
}
