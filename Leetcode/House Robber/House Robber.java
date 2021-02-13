class Solution {
    public int rob(int[] nums) {
        // This will be the total number of houses available
        int size= nums.length;
        // If there are no houses available, we cannot rob money
        if(size==0){
            return 0;
        }
        // Initialising dp array. This array will contain the maximum amount according to the number of houses we have
        int[] dp= new int[size+1];
        //If we have 0 houses, we cannot rob money
        dp[0]=0;
        // If we have 1 house, we can rob the first house
        dp[1]= nums[0];
        // This loop will store the maximum value for index i representing number of houses available
        for(int i=1;i<size;i++){
            // This gives us the maximum value between if we skip the current house or skip the previous immediate house
            dp[i+1]= Math.max(dp[i],dp[i-1]+ nums[i]);
        }
        // Since we have "size" number of houses, this will be our maximum answer
        return dp[size];
    }
}
