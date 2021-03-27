// * ALGORITHM ==>
// * This question is the application of Longest Increasing Subsequence. 
// * To do this question we want to generate an increasing order in both the dimensions, width as well as height.
// * So firstly we sort the width to get an increasing order there.
// * Then we calculate the LIS for every height, travelling in the order of increasing width.
// * But the problem can happen when there are duplicate values.
// * To tackle them we modify our LIS, so that only those combinations for each index get selected, whose width as well as the height is less then the current envelope width and height.
// * So for every index, we check if (current_height > previous_height && current_width > previous width) , so that we can guarantee that the smaller sized envelope can fit into the larger sized envelope.

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        // * O(n^2) solution
        int n = (int)envelopes.size(), _max = 1;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (envelopes[j][1] < envelopes[i][1] && envelopes[j][0] < envelopes[i][0])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            _max = max(_max, dp[i]);
        }
        return _max;
    }
};
