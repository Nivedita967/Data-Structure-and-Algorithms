// * ALGORITHM ==>
// * In this we initialise the dp array for 0th and 1st index.
// * From each i >= 2 we move back and try to minimise the number of squares needed to sum up to 'i' and we only see values in the range of {1 - - - - sqrt(i)}.
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        // * Return dp of last element i.e. n
        return dp[n];
    }
};
