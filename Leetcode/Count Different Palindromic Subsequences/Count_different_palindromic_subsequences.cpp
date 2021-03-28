// * ALGORITHM ==>
// * In this algorithm we first keep an account of next and previous occurrence for each character of the string . If not then -1.
// * Using the gap method , we maintain following subcases :
// * Subcase 1: when gap = 0
// * Subcase 2: when gap = 1
// * Subcase 3: when two extreme characters are same and never occurred in between
// *  Subcase 4: when two extreme characters are same and occurred for once in between
// *  Subcase 5: when two extreme characters are same and occurred for at least 2 times in between
// * Subcase 6: when two characters at extreme are different

class Solution
{
public:
    int countPalindromicSubsequences(string S)
    {
        vector<int> next(S.size(), -1);
        vector<int> prev(S.size(), -1);
        unordered_map<char, int> mymap1;

        // * For previous occurrence of each character
        for (int i = 0; i < S.size(); i++)
        {
            if (mymap1.count(S[i]) >= 0)
            {
                prev[i] = mymap1[S[i]];
            }
            mymap1[S[i]] = i;
        }

        // * For next occurrence of each character
        unordered_map<char, int> mymap2;
        for (int i = S.size() - 1; i >= 0; i--)
        {
            if (mymap2.count(S[i]) >= 0)
            {
                next[i] = mymap2[S[i]];
            }
            mymap2[S[i]] = i;
        }
        int N = 1e9 + 7;
        vector<vector<int>> dp(S.size(), vector<int>(S.size(), 0));
        for (int gap = 0; gap < S.size(); gap++)
        {
            for (int i = 0, j = gap; j < S.size(); i++, j++)
            {

                // * Subcase 1
                if (gap == 0)
                {
                    dp[i][j] = 1;
                }

                // * Subcase 2
                else if (gap == 1)
                {
                    dp[i][j] = 2;
                }
                else
                {
                    if (S[i] == S[j])
                    {
                        int n = next[i];
                        int p = prev[j];

                        // * Subcase 3
                        if (n > p)
                        {
                            dp[i][j] = ((2 * dp[i + 1][j - 1]) % N + 2) % N;
                        }

                        // * Subcase 4
                        else if (n == p)
                        {
                            dp[i][j] = ((2 * dp[i + 1][j - 1]) % N + 1) % N;
                        }

                        // * Subcase 5
                        else
                        {
                            dp[i][j] = ((2 * dp[i + 1][j - 1]) % N - dp[n + 1][p - 1] + N) % N;
                        }
                    }

                    // * Subcase 6
                    else
                    {
                        dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1]) % N - dp[i + 1][j - 1] + N) % N;
                    }
                }
            }
        }
        return dp[0][S.size() - 1];
    }
};
