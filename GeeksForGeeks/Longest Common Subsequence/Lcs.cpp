// * ALGORITHM ==>
// * In this we create a 2d dp array where each cell of dp stores a possible subsequence
// * Then we calculate longest common subsequence of the two strings by following two subcases:
// * Subcase 1 : when extreme characters of two strings are same
// * Subcase 2 : when extreme characters of two strings are different

class Solution
{
public:
    int lcs(int x, int y, string s1, string s2)
    {

        // your code here
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
        for (int i = x - 1; i >= 0; i--)
        {
            for (int j = y - 1; j >= 0; j--)
            {

                // * Subcase 1;
                if (s1[i] == s2[j])
                {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }

                // * Subcase 2;
                else
                {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        // * Returning final answer
        return dp[0][0];
    }
};
