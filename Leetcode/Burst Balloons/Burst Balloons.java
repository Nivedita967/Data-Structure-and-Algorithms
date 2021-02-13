class Solution {
    public int maxCoins(int[] nums) {
      // Finding the size of our coins array
        int size= nums.length;
        // If there are no coins, then we cannot score
        if(size==0){
            return 0;
        }
        // Initialising dp array. Here we will vary the number of elements chosen as n.
        //For each n, we will find the ans
        int dp[][] = new int[size][size];
        for(int n=0;n<size;n++){
          // i denotes the leftmost bound of the subproblem
            for(int i=0;i+n<size;i++){
              // j denotes the rightmost bound of the subproblem
                int j= i+n;
                // Traversing from leftmost bound to rightmost bound using k
                for(int k=i;k<=j;k++){
                  // If our leftmost bound is first element, then we want to multiply with 1
                  // Otherwise we will multiply with nums[i-1]
                    int leftValue= i==0? 1: nums[i-1];
                  //If our rightmost bound is last element, then we want to multiply with 1
                  // Otherwise we will multiple with nums[j+1]
                    int rightValue= j==size-1?1: nums[j+1];

                  // If our k is equal to leftmost bound, then we have nothing on the left
                  // Otherwise we have the left side ans stored in our dp array
                    int left= k==i?0: dp[i][k-1];
                  // If our k is equal to rightmost bound, then we have nothing on the right
                  // Otherwise we have the right side ans stored in our dp array
                    int right= k==j?0: dp[k+1][j];

                  // Calculating the maximum score for our given leftmost and rightmost bounds
                    dp[i][j]= Math.max(dp[i][j], leftValue*nums[k]*rightValue + left+ right);
                }
            }
        }
        // Our question's answer will have leftmost bound as 0 and rightmost bound as n-1
        return dp[0][size-1];
    }
}
