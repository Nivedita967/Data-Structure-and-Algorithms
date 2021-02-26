class Solution {
    public int minCostClimbingStairs(int[] cost) {
        //Finding the size of cost array
        int size= cost.length;
        //Initialising dp array which will store minimum cost for i stairs
        int[] dp= new int[size];
        //We can either start from first step or second step
        dp[0]= cost[0];
        dp[1]= cost[1];
        
        //Looping trough rest of the stairs
        for(int i=2;i<size;i++){
            //Finding the minimum cost for current stair
            dp[i]= Math.min(dp[i-1]+ cost[i], dp[i-2]+ cost[i]);
        }
        // We can take one step or two step forward to reach final stair.
        //So all we need to do is find the minimum cost to reach size-1 or size-2 stairs, and then we can climb to the final stair
        return Math.min(dp[size-1], dp[size-2]);
    }
}
