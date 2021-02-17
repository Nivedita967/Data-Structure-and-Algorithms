#include<bits/stdc++.h>
using namespace std;

//typedef is a keyword in c++ used to give an alternative name to a data type 
typedef long long int ll;

//function definition 
void solve()
{
    // declaration of required variables
    ll N,M;
    ll x,prefix=0,maxim=0;

    //inputting two spaces seperated integers 
    cin>>N>>M;
    set<ll> S;

    //using inbuilt function for inserting 0
    S.insert(0);

    //loop for taking input of n elements and calculation of maximum subarray sum
    for(int i=1;i<=N;i++)
    {
        cin>>x;
        prefix = (prefix + x)%M;

        maxim = max(maxim,prefix);    //max is an inbuilt funtion used to find the maximum of the passed parameters
        set<ll>::iterator  it = S.lower_bound(prefix+1);
        if( it != S.end() ){
            maxim = max(maxim,prefix - (*it) + M );
        }
        S.insert(prefix);
    }

    //printing the result 
    cout<<maxim<<endl;
}

int main()
{
    //declaration of no of queries to be performed
    int T;

    // inputting no of queries
    scanf("%d",&T);

    // loop for running queries 
    while(T--)   
    {
        //function for finding maximum subarray sum
         solve();
    }
    return 0;
}
