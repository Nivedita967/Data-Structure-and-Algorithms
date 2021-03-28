// * ALGORITHM ==>
// * In this algorithm we use the gap method to iterate over all possible substrings , check which of them are palindromic and which of them are longest.
// * For this we have following subcases:
// * Subcase 1: When Gap ==0 (base case)
// * Subcase 2: When Gap ==1 (base case)
// * Subcase 3: When two characters at i & jth position are same.
// * Subcase 4: When two characters at i & jth position are different.
// * We store those i and j indexes at which we will get Longest Palindromic Substring and later on using substr we get our final string.

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = (int)s.size(), max_i = -1, max_j = -1, _max = 0, old_max = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                // * Subcase 1:
                if (g == 0)
                {
                    dp[i][j] = true;
                    _max = max(_max, g + 1);
                }
                // * Subcase 2;
                else if (g == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = true;
                        _max = max(_max, g + 1);
                    }
                }

                else
                {
                    // * Subcase 3;
                    if (s[i] == s[j] && dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        _max = max(_max, g + 1);
                    }
                }

                // * Storing index i & j where we get longest Palindromic Substring
                if (old_max != _max)
                {
                    old_max = _max;
                    max_i = i;
                    max_j = j;
                }
            }
        }
        // * Returning final resultant string
        return s.substr(max_i, max_j - max_i + 1);
    }
};
