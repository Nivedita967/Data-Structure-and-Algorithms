
/*make one array dp of length same as A, and fill this with 0
for i in range 0 to length of A - 1
dp[i] = A[i] + dp[i - 1] if i – 1 >= 0 otherwise 0
temp := A[i]
for j in range 1 to k – 1
if i – j >= 0
index := i – j
temp := max of temp and A[i - j]
if index – 1 >= 0, then
dp[i] := max of dp[i] and (temp*(i – index + 1) + dp[index - 1])
otherwise dp[i] := max of dp[i] and 0
return last element of dp*/
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