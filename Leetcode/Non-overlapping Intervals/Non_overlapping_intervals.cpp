// * Algorithm ==>
// * Approach used : Longest Increasing Subsequence
// * In this we first sort the intervals array on the basis of first value. 
// * Then we calculate Longest Increasing Subsequence on the intervals array on the basis of the second value keeping in mind that south of the current element must be greater than north of the previous element. This is done in order to get non overlapping intervals.  
// * At last in order to get minimum intervals that can be removed , we subtract maximum non overlapping intervals from the length of intervals array, i.e. total - num of max non overlapping = min to be removed!
// * This approach uses O(n^2) 

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
        {
            return 0;
        }
        int n = (int)intervals.size(), _max = 1;
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (intervals[j][1] <= intervals[i][0])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            _max = max(_max, dp[i]);
        }
        return n - _max;
    }
};
