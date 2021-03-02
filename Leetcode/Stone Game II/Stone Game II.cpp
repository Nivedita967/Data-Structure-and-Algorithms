#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   int stoneGameII(vector<int>& piles)
    {
        //calculating size of vector
        int n = piles.size();

        //if the vector is empty
        if(n == 0)  
            return 0;
        
        //declaring vector 
        vector<int>sum(n+1, 0);
        
        //storing in sum
        for(int i=n-1; i>=0; i--)
        {
           sum[i] = piles[i] + sum[i+1]; 
        }  

        //declaring a vector matrix         
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));

        //storing in the matrix 
        for(int i = 0; i <= n; i++)
        {
            dp[i][n] = sum[i];
        }    
        
        //calculating no of stones
        for(int i=n-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                for(int x=1; x<=2*j && i+x<=n; x++)
                 {    dp[i][j] = max(dp[i][j], sum[i] - dp[i+x][max(j,x)]); }
            }
        }

        //returning maximum no of stones alice can get
        return dp[0][1];
    }
};