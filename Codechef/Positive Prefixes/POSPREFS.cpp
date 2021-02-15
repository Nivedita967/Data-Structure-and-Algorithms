// Problem Link - https://www.codechef.com/problems/POSPREFS

#include <bits/stdc++.h>
#define ll long long
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);


using namespace std;

int main()  // Main Function
{
    ll te,j;
    cin>>te;
    while(te--)
    {
        ll n,k,i,sum=0;
        cin>>n>>k;  // Taking Inputs
        ll vect[n+1];
        for(i=1;i<=n;)
        {
            if(k==0 or k==n)
            break;
            if(sum+i<=i+1 and k>0)
            {
                vect[i] = i;
                sum+=i;
                i++;
                k--;
                continue;
            }
            if(sum>i)
            {
                vect[i]=-i;   
                sum -=i;
                i++;                
                if(sum>0)
                k--;
                continue;
            }
            if(sum+i>i+1 and k==1)
            {
                vect[i]=-i;
                i++;
                if(sum-i>0)
                break;
                else
                {
                    sum-=i;
                    continue;
                } 
            }
            if(sum+i>i+1 and k>1)
            {
                vect[i] = i;
                if(sum>0)
                k--;
                sum+=i;
                i++;
            }
        }
        if(k==n)
        {
            for(i=1;i<=n;i++)
            {
                vect[i] = i;
            }
        }
        else if(i<=n)
        {
         for(;i<=n;i++)
         {
             vect[i]=-i;
         }
        }
        for(i=1;i<=n;i++)
        {
            cout<<vect[i]<<" ";         //Printing Output
        }
        cout<<"\n";
    }
    return 0;
}
