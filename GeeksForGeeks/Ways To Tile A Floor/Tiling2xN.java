class Solution {
    static Long numberOfWays(int n) {
        // code here
        int N = 1000000007; 
        //storing number of ways to tile in DP array
        Long[] dp = new Long[n + 1];
        
        // to tile 2 x 1 , we have only 1 option
        dp[1] = Long.parseLong("1");
        if(n == 1) return dp[1];
        
        // to tile 2 x 2 , we have two options
        dp[2] = Long.parseLong("2");
        if(n == 2) return dp[2];
        
        // for all other we have two ways to place the tile horizontally or vertically
        for(int i = 3; i <= n; i++){
            dp[i] = (( dp[i - 2] % N) + (dp[i - 1] % N) % N); 
        }
        return dp[n] % N; 
    }
};