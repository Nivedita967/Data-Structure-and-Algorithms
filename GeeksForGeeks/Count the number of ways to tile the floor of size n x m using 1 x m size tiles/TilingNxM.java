class Solution
{
    public int countWays(int n, int m)
    {
        // Code here
        int N = 1000000007; // to take modulo for large numbers

	    // dp array initially with 0
        int[] dp = new int[n+1];
	    Arrays.fill(dp, 0);

        for(int i = 1 ; i <= n; i++){
            // all the values < m would have only 1 way to place the tile
            if(i < m){
                dp[i] = 1;
            }

            // all the values = m would have 2 ways to place the tile ( horizontally & vertically )
            else if(i == m){
                dp[i] = 2;
            }

            // all other values of floor would have 2 ways to place the tile ( horizontally & vertically )
            else{
                dp[i] = ( dp[i-m] % N + dp[i-1] % N ) % N;
            }
        }
        return dp[n];
    }
}