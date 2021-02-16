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
#define mp make_pair
#define MOD 1000000007
 
using namespace std;

void its_Function()
{
    ll NT_MIN,n,maxi=INT_MIN,mini=INT_MAX,p=1,k,q; //Initializing Variables
  cin>>n;
  vec v(n);
  for(ll i =0;i<n;i++)
  {
      cin>>v[i];
  }
  ll fuel = v[0]; // Taking initaial value of the fuel as the first element of the vector
  ll dis = 0;
  for(ll i =1;i<n;i++)
  {
      if(fuel!=0)  // Ckecking if the fule is left or not
      {
      fuel -= 1; // If fuel is not finished then decrease it by one for the trip
      dis+=1;
      fuel+=v[i]; // Increasing the fuel value by the value of the fuel available at next stop
      }
  }
  cout<<dis+fuel;  //Printing Output
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
