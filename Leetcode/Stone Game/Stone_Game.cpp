#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
   bool stoneGame(vector<int>& piles)
   {
       //calculating size of the array piles
      int n = piles.size();

      //declaring a matrix dp if size n*n 
      vector < vector <int> > dp(n,vector <int>(n));

      //declaring an array of size n+1
      vector <int> pre(n + 1);

      //taking stones 
      for(int i = 0; i < n; i++)
      {
         pre[i + 1] = pre[i] + piles[i];
      }
      for(int l = 2; l <= n; l++)
      {
         for(int i = 0, j = l - 1; j < n; i++, j++)
         {
            dp[i][j] = max(piles[j]+pre[j]-pre[i]-dp[i][j-1],piles[i]+pre[i+2]- pre[j]+dp[i+1][j]);
         }
      }

      //returning true if only Alex wins
      return dp[0][n - 1] > dp[0][n - 1] - pre[n];
   }
};
