// * ALGORITHM ==>
// * In this question, we maintain the count of combinations of whether the last 2 fences were of the same color or different colors.
// * If we were to paint total of 'i' fences, and the last 2 fences have the same color, then we calculate the number of combinations of a total of 'i - 1' fences where the last 2 have the different color. We don't include the same color fences because if we do that then there will be 3 consecutive fences having the same color.
// * In general for any given i (total number of fences), if we were to paint the last 2 fences with same color, then it will be equal to ==> dp[i]{same} = dp[i - 1]{different} and if we want them to be of different colors, then total combinations will equal ==> dp[i]{different} = dp[i - 1] * k {same + different} 


#define mod 1000000007
// * Solution Class
class Solution
{
public:
    long long countWays(int n, int k)
    {
        // code here
        long long same = 0, diff = 0, total = 0;
        same = k;
        if (n == 1)
        {
            return k;
        }
        diff = (k * (k - 1)) % mod;
        total = (same + diff) % mod;
        for (int i = 3; i <= n; i++)
        {
            same = diff;
            diff = (total * (k - 1)) % mod;
            total = (same + diff) % mod;
        }
        return total;
    }
};