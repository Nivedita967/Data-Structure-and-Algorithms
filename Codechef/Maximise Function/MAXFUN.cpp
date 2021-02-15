#include <bits/stdc++.h> 
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define ll long long

 

using namespace std;



ll its_Function()
{
   ll n;
   cin>>n;
   vector<ll> vect(n);
   for(ll i=0;i<n;i++)
   {
       cin>>vect[i];
   }
   ll maxi = -1;
   ll sum = 0;
   sort(vect.begin(),vect.end());
   ll end = vect[n-1];
   ll one  = vect[0];
   ll two = vect[1];
   maxi = (vect[n-1]-vect[0]) + (vect[n-1]-vect[1]) + (vect[1] - vect[0]);
   return maxi;
}
int main()
{   
 
	BOOST;
    ll t;
    cin>>t;
    while(t--)
    {
    ll ans = its_Function();
    cout<<ans<<"\n";
    }
	return 0;	
}

