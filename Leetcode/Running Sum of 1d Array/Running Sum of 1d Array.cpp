class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        // Creating one array
        vector<int>dp(n);
        dp[0] = nums[0];
        // Looping through to fill the values
        for(int i = 1 ; i < n ;i++)
        {
            dp[i] = dp[i-1] + nums[i];
        }
        // returning vector at last
        return dp;
    }
};