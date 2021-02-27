#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& A) 
  {
    //calculating size of the vector  
    int n = A.size();

    //calculating size of of a row
    int m = A[0].size();

    //declaration of a vector 
    vector<vector<int>> dp(n + 2, vector<int>(m + 2));
          
     //calculating failing paths sum    
    for (int i = 1; i <= n; ++i)
     {
      dp[i][0] = dp[i][m + 1] = INT_MAX;
      for (int j = 1; j <= m; ++j)
      {  
           dp[i][j] = *min_element(dp[i - 1].begin() + j - 1, 
                                dp[i - 1].begin() + j + 2) + A[i - 1][j - 1];      
      }
    }

    //returning minimum failling path sum
    return *min_element(dp[n].begin() + 1, dp[n].end() - 1);
  }
};