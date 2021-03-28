// * ALGORITHM ==>
// * In this algorithm we keep dp array to store distinct subsequences till this index in the cell
// * For this we have following subcases:
// * Subcase 1: When the character has occurred before
// * Subcase 2: When the character has not occurred before
// * In this solution we maintain a last index record for each character to remove the duplicate subsequences that occur.

class Solution
{
public:
    int distinctSubseqII(string S)
    {
        int mod = 1e9 + 7;
        // * mymap to maintain last index;
        unordered_map<char, int> my_map;
        vector<long long int> dp((int)S.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= (int)S.size(); i++)
        {
            // * Subcase 1;
            if (my_map.count(S[i - 1]) == 0)
            {
                dp[i] = (((2 * dp[i - 1]) % mod) + mod) % mod;
            }
            // * Subcase 2;
            else
            {
                int prev_loc = my_map[S[i - 1]];
                dp[i] = (((2 * dp[i - 1]) % mod) - (dp[prev_loc - 1] % mod) + mod) % mod;
            }
            // * always update the last visit of each character
            my_map[S[i - 1]] = i;
        }
        // * Returning final count of non empty subsequences
        return dp[S.size()] - 1;
    }
};
