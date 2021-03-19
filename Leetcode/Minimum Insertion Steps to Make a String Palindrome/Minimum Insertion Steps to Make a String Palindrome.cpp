#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
        int minInsertions(string s)
        {
            //required declarations
            int n=s.size(); 
            int dp[n][n];
            
            //seeting the value of dp
            memset(dp,0,sizeof dp);
            
            //loop for finding minimum insertion steps
            for(int i=n-1;i>=0;i--)
            {
                for(int j=i;j<n;j++)
                {
                    if(i>=j){  dp[i][j]=0;}
                    else if(s[i]==s[j]){dp[i][j]=dp[i+1][j-1];}
                    else {dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);}
            }
        }
            
        //returning minimum no of insertion steps    
        return dp[0][n-1];
    }
};