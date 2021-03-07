#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        //finding longest common subsequence
        int com_len=longestCommonSubsequence(word1, word2);

            //calculating and returning longest common subsequence
            int res = word1.size()+word2.size()-2*com_len;
            return res;
    }
        int longestCommonSubsequence(string text1, string text2)
         {
             //taking sizes of both the strings
            int m = text1.size(), n = text2.size();

            //checking if both the strings are there i.e if one of them is empty it will return 0
                if (!m || !n) return 0;

            //declaration of vector
            vector<vector<int>> dp(m, vector<int>(n,0));

            //if first character is same 
            if (text1[0]==text2[0]) dp[0][0]=1;

            //loops for checking how many common alphabets are there
            for (int i=1; i<m; i++)
            {
                    if (text1[i]==text2[0]||dp[i-1][0]==1) dp[i][0]=1;
            }
            for (int i=1; i<n; i++)
            {
                    if (text2[i]==text1[0]||dp[0][i-1]) dp[0][i]=1;
            }
            for (int i=1; i<m; i++)
            {
                    for (int j=1; j<n; j++)
                    {
                            if (text1[i]==text2[j]) dp[i][j]=dp[i-1][j-1]+1;
                            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                    }
            }

            //returning no of common subsequence
            return dp[m-1][n-1];
    }
};