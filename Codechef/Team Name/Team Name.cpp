#include <bits/stdc++.h> 
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define ll long long


using namespace std;


void its_Function()
{
  ll n;
  cin>>n; // taking the value of n
  map<string,vector<char>> m;  // making a map m
  string str;
  for(ll i=0;i<n;i++)
  {
      cin>>str;
      if(str.length()>0)
      m[str.substr(1)].push_back(str[0]);   // Taking string as the input and putting its first element as the key
  }                                         // and rest charecters as the value     
ll ans=0;
  for(auto i:m)
  {
      for(auto j:m)
      {
          if(i.first!=j.first)
          {
                ll count = 0;
              vector<char> v1,v2;
              v1 = i.second;                                    //Taking value of map
              v2 = j.second;                                    //Taking value of map   
              set<char> s(v1.begin(),v1.end());
              for(auto k: v2)
              {
                  if(s.find(k)!=s.end())                   //checking the logic
                  {
                      count++;                              // Increasing the count on the basis of condition
                  }
              }
             ans+=(i.second.size()-count)*(j.second.size()-count); // Main logic of the code
          }
      }
  }
  cout<<ans; //Printing the output
}

int main()
{   
 
	BOOST;
    ll t;
    cin>>t;
    while(t--)
    {
    its_Function();
    cout<<"\n";
    }
	return 0;	
}


