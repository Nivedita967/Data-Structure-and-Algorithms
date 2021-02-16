#include <bits/stdc++.h>
#define ll long long
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define vec  vector<ll>
#define pb push_back
#define vec  vector<ll>
#define pi vector<pair<ll,ll>>
#define fi first
#define se second
#define pb push_back
#define sz size()
#define eb emplace_back
#define mp make_pair
#define MOD 1000000007
 
using namespace std;

void its_Function()  //Working Function of the code.
{
    ll NT_MIN,n,maxi=INT_MIN,mini=INT_MAX,p=1,k,q; //Initialising variables
    cin>>n;
    vec v(n);
    for(ll i =0;i<n;i++)
    {
        cin>>v[i];
    }
    ll sum = accumulate(v.begin(),v.end(),0);
    if(sum<0)
    {
        cout<<"NO";
    }
    else
    {
          cout<<"YES";
    }
}
 
int main() //Main Function
{   
 
	BOOST;
	ll t;
	cin>>t;
	while(t--)
	{
    its_Function(); //Calling Function
    cout<<"\n";
	}
	return 0;
	
}
