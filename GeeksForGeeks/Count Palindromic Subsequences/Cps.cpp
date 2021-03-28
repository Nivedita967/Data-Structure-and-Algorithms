// * ALGORITHM ==>
// * In this algorithm we use the gap method to iterate over all possible substrings, check which of them are palindromic and figure out the longest palindrome.
// * For this we have following subcases:
// * Subcase 1: When Gap ==0 (base case)
// * Subcase 2: When Gap ==1 (base case)
// * Subcase 3: When two characters at i & jth position are same.
// * Subcase 4: When two characters at i & jth position are different.
class Solution
{
public:
    long long int countPS(string str)
    {
        //Your code here
        int n = (int)str.size(), mod = 1e9 + 7;
        vector<vector<long long int>> dp(n, vector<long long int>(n, 0));
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                // * Subcase 0;
                if (g == 0)
                {
                    dp[i][j] = 1;
                }
                // * Subcase 1;
                else if (g == 1)
                {
                    str[i] == str[j] ? dp[i][j] = 3 : dp[i][j] = 2;
                }

                else
                {
                    // * Subcase 3;
                    if (str[i] == str[j])
                    {
                        dp[i][j] = ((dp[i][j - 1] + dp[i + 1][j]) % mod + 1) % mod;
                    }

                    // * Subcase 4
                    else
                    {
                        dp[i][j] = ((dp[i][j - 1] + dp[i + 1][j]) % mod - dp[i + 1][j - 1] + mod) % mod;
                    }
                }
            }
        }
        // * Return value at first row last column
        return dp[0][n - 1];
    }
};
