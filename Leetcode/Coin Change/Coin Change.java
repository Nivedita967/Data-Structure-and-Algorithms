class Solution {
    public int coinChange(int[] coins, int amount) {
        //Initialising dp array which will contain fewest coins for each amount
        int[] dp = new int[amount+1];
        //Initially filling the array with amount+1 
        Arrays.fill(dp,amount+1);
        //To make 0 amount, we need 0 coins
        dp[0]=0;
        //Looping for each amount
        for(int i=0;i<=amount;i++){
            //Looping through each coin in the given array
            for(int j=0;j< coins.length;j++){
                // If we are able to take that coin
                if(coins[j]<= i){
                    //Finding minimum coins for i amount
                    dp[i]= Math.min(dp[i],1+ dp[i-coins[j]]);
                }
            }
        }
        //If we are not able to make amount,we return -1 else we return dp[amount]
        return dp[amount]> amount? -1: dp[amount];
    }
}
