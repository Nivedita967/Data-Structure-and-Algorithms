#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int uniquePaths(int m, int n)
    {
         //create a dp table of size (mxn) and initialize all values to zero      
        vector<vector<long long>> dp(m, vector<long long>(n,0));
        //initialize the first row and column vlaues to 1  
         for(int i=0;i<m;++i)        
         { 
             for(int j=0; j<n ;++j) 
            {
                if(i==0 || j==0)
                {
                    //if we are at 1st row or 1st column so initialize to value 1
                    dp[i][j]=1;
                }
                else
                {
                    //else dp[i][j] = sum of left cell +above cell because we can arrive a cell at(i,j)
                  dp[i][j] = dp[i-1][j] + dp[i][j-1];   
                }
            }
         }
        // return the vlaue in the last cell  
        return dp[m-1][n-1];
    }
};