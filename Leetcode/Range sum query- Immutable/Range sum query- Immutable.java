class NumArray {
    //Declaring dp array outside so it is accessible to both methods
    int[] dp;
    
    public NumArray(int[] nums) {
        //Finding the size of given array
        int size= nums.length;
        //Declaring the size of dp array
        dp= new int[size+1];
        //For 0 elements... sum is 0
        dp[0]= 0;
        //Looping from 1 to n to find sum till i elements
        for(int i=1;i<=size;i++){
          dp[i]= dp[i-1]+ nums[i-1];
        }
    }
    
    public int sumRange(int i, int j) {
        //Returning the difference between sum of j elements and sum of i elements to find answer
        return dp[j+1]- dp[i];
    }
}
