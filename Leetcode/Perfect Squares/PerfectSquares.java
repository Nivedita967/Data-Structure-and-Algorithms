class Solution {
    public int numSquares(int n) {
        //dp array
        int[] dp = new int[n+1];
        Arrays.fill(dp, Integer.MAX_VALUE);

        // initialising dp[0] & dp[1];
        dp[0]=0;
        dp[1]=1;

        // from i >=2 we look back for all perfect squares and store min value
        for(int i=2; i<=n; i++){
            for(int j=1; j*j <=i; j++){
                dp[i]= Math.min(dp[i], dp[i-(j*j)]+1);
            }
        }
        //returning dp[n]
        return dp[n];
    }
}