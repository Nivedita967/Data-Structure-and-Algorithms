class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
int n = A.size();
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        int curMax = 0;
        for (int j = 1; j <= K && i - j + 1 >= 0; ++j) {
            curMax = max(curMax, A[i - j + 1]);
            dp[i] = max(dp[i], (i >= j ? dp[i - j] : 0) + curMax * j);
        }
    }
    return dp.back();
    }
};