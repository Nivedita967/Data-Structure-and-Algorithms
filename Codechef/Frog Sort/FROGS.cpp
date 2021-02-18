#include <bits/stdc++.h> 
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define ll long long

 

using namespace std;


void io()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
}  

ll getIndex(vector<ll> v, ll K)
{
    auto it = find(v.begin(), v.end(), K);
    if (it != v.end()) 
    {
        int index = it - v.begin();
        return index;
    }
    else {
        return -1;
    }
}


ll its_Function()
{
    ll n;
    cin>>n;  //Taking Input
    vector<ll> r(n), p(n), w(n),pos(n);
    for(ll i=0;i<n;i++)
    {
        cin>>p[i];
        pos[i] = i;
    }
    for(ll i=0;i<n;i++)
    {
        cin>>w[i];
    }
    r = p;
    sort(r.begin(),r.end());
    ll count=0;
    for(ll i=1;i<n;i++)
    {
      ll frog = r[i];
      ll index = getIndex(p,frog);
      ll c = index;
      ll preindex = pos[getIndex(p,frog-1)];  //Calling get index function
      while(index<=preindex)
      {
          index+=w[c];
            pos[c] = index;
          count++;
      }
    }
    
    return count;  //Returning Output
}

int main()  //Main Function
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




