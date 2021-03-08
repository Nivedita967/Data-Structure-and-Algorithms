class Solution {
    public int maxProfit(int[] prices, int fee) {


        int prof=0; //calculates profit
        int [][]dp= new int[2][prices.length]; //2D dp array
        dp[0][0]= 0-prices[0];
        dp[1][0]= 0;

        //loop on prices array
        for(int i=1; i<prices.length; i++){
            dp[0][i]= Math.max(dp[0][i-1] , dp[1][i-1]-prices[i]);  //stores buy profit till now
            dp[1][i]= Math.max(dp[0][i-1] + prices[i]- fee, dp[1][i-1]); //stores sell profit till now
        }
        
        prof= dp[1][prices.length -1];
        return prof;
    }
}