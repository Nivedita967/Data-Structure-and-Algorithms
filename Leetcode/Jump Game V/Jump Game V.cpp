#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    
    //declaration of variables
    int n;
    vector<int>a;
    int dp[1001]={0};
    
    //function
    int jumps(int i,int d)
    {
        //checking the condition  
        if(dp[i]!=0)
        {   return dp[i]; }
        
        //declaration of variables
        int res=1;
        int curr=a[i];
        
        //loops for finding the indices 
        for(int j=i+1;j<=min(n-1,i+d);j++)
        {
            if(a[j]<curr)
            {
                res=max(res,1+jumps(j,d));
            }
            else
                break;
        } 
        for(int j=i-1;j>=max(0,i-d);j--)
        {
            if(a[j]<curr)
            {
                res=max(res,1+jumps(j,d));
            }
            else
                break;
        }
        
        //returning variables
        return dp[i]=res;
    }
    
    //function 
    int maxJumps(vector<int>& arr, int d) 
    {
        //declaration of variables
        a=arr;
        n=a.size();
        int res=0;
        
        //loop for finding maximum 
        for(int i=0;i<n;i++)
        { res=max(res,jumps(i,d));}
        
        //returning maximum number of indices 
        return res;
    }
};