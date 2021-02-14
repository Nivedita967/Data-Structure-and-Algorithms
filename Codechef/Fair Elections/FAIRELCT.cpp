// Problem Link - https://www.codechef.com/JAN21B/problems/FAIRELCT

#include <bits/stdc++.h> 
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define ll long long

 

using namespace std;



ll its_Function()
{
    ll n,m,sum1=0,sum2=0;
    cin>>n>>m;
    vector<ll> vect1(n),vect2(m);
    for(ll i=0;i<n;i++)
    {
        cin>>vect1[i];
        sum1+=vect1[i];
    }
    for(ll i=0;i<m;i++)
    {
        cin>>vect2[i];
        sum2+=vect2[i];
    }
    sort(vect1.begin(),vect1.end());
    sort(vect2.begin(),vect2.end());
     ll k=0,count = 0;
    if(sum1>sum2)
    {
        return 0;
    }
    else
    {
        for(ll i = m-1;i>=0;i--)
        {
           if(k<n)
           {
               count++;
               sum1-=vect1[k];
               sum1+=vect2[i];
               sum2+=vect1[k];
               sum2-=vect2[i];
               if(sum1>sum2)
               {
                   return count;
               }
               k++;
           }
        }
    }
    return -1;
}
 
int main()
{   
 
	BOOST;
	ll t,ans;
	cin>>t;
	while(t--)
	{
    ans = its_Function();
    cout<<ans<<"\n";
	}
	return 0;
	
}
