class Solution {
public:
    int climbStairs(int n) {
        //Defining dp array that will contain distinct ways for i elements
        int dp[n+1];
        //To climb 1 step, only 1 way is there
        dp[0]= 1;
        //To climb 2 steps, there are 2 ways as shown in example input
        dp[1]= 2;
        // For i stairs, distinct ways will be equal to sum of total ways to reach i-1 stairs and i-2 stairs
        for(int i=2;i<n;i++){
            dp[i]= dp[i-1]+ dp[i-2];
        }
        // Returning the ans
        return dp[n-1];
    }
};
