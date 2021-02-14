class Solution {
    public boolean canPartition(int[] nums) {
        // Let sum of the two resulting subsets be S1 and S2. We want S1= S2
        // and S1+S2= arraySum
        // Thus, we want to find S1 such that S1 = arraySum/2.
        
        // Finding length of the given array
        int n = nums.length;
        // Finding the arraySum
        int arraySum = 0;
        for(int i=0;i<n;i++){
            arraySum += nums[i];
        }
        // If our arraySum is odd, there is no solution
        if(arraySum%2 != 0){
            return false;
        }
        //Defining the subsetSum that we want to achieve
        int subsetSum = arraySum/2;
        
        // Initialising dp array which will contain whether a given sum is possible with given number of elements
        int[][] dp = new int[n+1][subsetSum +1];
        //Initialising base cases for our dp array
        for(int i=0;i<n+1;i++){
            for(int j=0;j<subsetSum+1;j++){
                if(i==0){
                    dp[i][j]= 0;
                }
            }
        }
        for(int i=0;i<n+1;i++){
            for(int j=0;j<subsetSum+1;j++){
                if(j==0){
                    dp[i][j]= 1;
                }
            }
        }
        // Looping through number of elements and checking if j as a sum is possible or not
        for(int i=1;i<n+1;i++){
            for(int j=1;j<subsetSum+1;j++){
                //If nums[i] is less than j, then we can consider the possibility of adding it to our subset
                if(nums[i-1]<= j){
                    dp[i][j]= dp[i-1][j-nums[i-1]] | dp[i-1][j];
                }
                //Else we will exclude it
                else{
                   dp[i][j]= dp[i-1][j]; 
                }
            }
        }
        //If we can find a subset from n elements that has as subsetSum, we return true
        if(dp[n][subsetSum]==1){
            return true;
        }
        else{
            return false;
        }
    }
}
