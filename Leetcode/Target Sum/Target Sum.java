class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int arraySum=0;
        //Finding the size of given array
        int n= nums.length;
        //Finding total sum of array
        for(int i=0;i<n;i++){
            arraySum+= nums[i];
        }
        //For invalid inputs, we return 0
         if (S > arraySum || S < -arraySum || S + arraySum < 0 || (S + arraySum) % 2 == 1) {
            return 0;
        }
        // We get two equations here:
        // Lets suppose some elements have + sign and some have - sign
        // So overall we will get (some elements sum)1 - (some elements sum)2= S
        // Also, we know that (some elements sum)1 + (some elements sum)2 = arraySum
        // Adding these both equations, the problem is deduced to finding a subarray
        // whose sum is equal to (S + arraySum)/2
        int subsetSum= (S+ arraySum)/2;
        //Defining dp vector and assigning 0 for base cases
        int[][] dp= new int[n+1][subsetSum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<subsetSum+1;j++){
                if(i==0){
                    dp[i][j]=0;
                }
            }
        }
        //We will have 1 solution for 0 sum with 0 elements
        dp[0][0]= 1;
        // Using two for loops, we are finding the answer recursively for i elements and j sum
        for(int i=1;i<n+1;i++){
            for(int j=0;j<subsetSum+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j]= dp[i-1][j-nums[i-1]]+ dp[i-1][j];
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        // Our final ans will be for n elements and subsetSum as our sum
        return dp[n][subsetSum];
    }
}
