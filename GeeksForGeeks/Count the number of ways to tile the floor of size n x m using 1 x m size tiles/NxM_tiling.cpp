// * Algorithm ==>
// * In this we use dynamic programming approach with different possible cases handled 
// * via if else conditions.
// * Case 1 : when n < m , then only 1 case will be possible to place the tiles
// * Case 2 : when n == m , then there will be 2 possible ways to place the tile i.e. horizontally or vertically
// * Case 3 : when m > n , in this case there will be two subcases possible:
// *    Subcase 1: when placed the tile lengthwise, make a call of dp[n-m];
// *    Subcase 2: when placed the tile width wise, make a call of dp[n-1];

//* At the end the number of tiles to floor n x m will be given by dp[n];


class Solution
{
public:
    int countWays(int n, int m)
    {
        // Code here.
        int N = 1000000007;
        vector<int> dp(n + 1, 0);
        if (m > n)
        {
            return 1;
        }
        for (int i = 1; i < m; i++)
        {
            dp[i] = 1;
        }
        dp[m] = 2;
        for (int i = m + 1; i <= n; i++)
        {
            dp[i] = ((dp[i - 1] % N) + (dp[i - m] % N) % N);
        }

        return dp[n] % N;
    }
};
