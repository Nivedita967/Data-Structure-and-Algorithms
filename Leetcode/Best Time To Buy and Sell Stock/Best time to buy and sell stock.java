class Solution {
    public int maxProfit(int[] prices) {
        // Defining the size of given array
        int size= prices.length;
        //Defining dp array. It will contain the maximum amount that can be achieved till i-1 elements
        int[] dp= new int[size+1];
        //Since only one day is available, no transaction is possible
        dp[0]=0;
        //We define the minimum amount that is present till now
        int mnm= prices[0];
        //Looping through the array
        for(int i=1;i<size;i++){
            //We find the maximum amount that can be made till i-1 elements
            dp[i]= Math.max(prices[i]- mnm, dp[i-1]);
            //If we find an amount less than minimum, we reassign minimum
            if(prices[i]<mnm){
                mnm= prices[i];
            }
        }
        //Returning the answer
        return dp[size-1];
    }
}
