class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    //Finding total sum of array
     int arraySum = accumulate(nums.begin(), nums.end(), 0);
        //For invalid inputs, we return 0
        if (S > arraySum || S < -arraySum || S + arraySum < 0 || (S + arraySum) % 2 == 1) {
            return 0;
        }
        // We get two equations here:
        // Lets suppose some elements have + sign and some have - sign
        // So overall we will get (some elements sum)1 - (some elements sum)2= S
        // Also, we know that (some elements sum)1 + (some elements sum)2 = arraySum
        // Adding these both equations, the problem is deduced to finding a subarray
        // whose sum is equal to (S + arraySum)/2
        int subsetSum = (S + arraySum) / 2;
        //Finding the size of given array
        int n = nums.size();

        //Defining dp vector and assigning 0 for base cases
        vector<vector<int>> dp(n + 1, vector<int>(subsetSum + 1, 0));
        //We will have 1 solution for 0 sum with 0 elements
        dp[0][0] = 1;
        // Using two for loops, we are finding the answer recursively for i elements and j sum
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= subsetSum; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (nums[i - 1] <= j) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        
       // Our final ans will be for n elements and subsetSum as our sum
        return dp[n][subsetSum];   
    }
};
