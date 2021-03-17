#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int palin(string s,string s1,int n,int m,int dp[1001][1001])
    {
        //if the strings are empty
        if(n == 0 || m ==0)
        {   return 0; }
        
        //if dp[n][m] have some number in it i.e not equal to -1
        if(dp[n][m] != -1)
         { return dp[n][m];}
        
        //if the element is same in both string
        if(s[n-1] == s1[m-1])
        {     
          //calling function recursively  
          return dp[n][m] = palin(s,s1,n-1,m-1,dp)+1;
        }    
        else
        {   
            //calling function recursively
            return dp[n][m] = max(palin(s,s1,n-1,m,dp),palin(s,s1,n,m-1,dp));
        }
    }
    int longestPalindromeSubseq(string s)
    {
        //taking the string passed as parameter
        string s1=s;
        
        //reversing the string
        reverse(s1.begin(),s1.end());
        
        //declaration
        int dp[1001][1001];
        
        //loop for initialisation of dp
        for(int i=0;i<1001;i++)
        {
            for(int j=0;j<1001;j++)
            {
                dp[i][j]=-1;
            }
        }
        
        //returning the output returned by the function call
        return palin(s,s1,s.size(),s1.size(),dp);
    }
};