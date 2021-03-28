class Solution {
    public int numSquares(int n) {
        //dp array
        int[] dp = new int[n+1];
        Arrays.fill(dp, Integer.MAX_VALUE);

        // initialising base values
        dp[0]=0;
        dp[1]=1;

        // filling all other values of dp array 
        for(int i=2; i<=n; i++){
            for(int j=1; j*j <=i; j++){
                dp[i]= Math.min(dp[i], dp[i-(j*j)]+1);
            }
        }

        // returning dp[n]
        return dp[n];
    }
}