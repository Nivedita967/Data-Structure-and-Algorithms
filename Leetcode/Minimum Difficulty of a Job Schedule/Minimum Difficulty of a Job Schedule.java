class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        //Finding the size of array
        int n = jobDifficulty.length;
        //If size is less than d, thenm return -1
        if(n < d){
           return -1; 
        } 
        //Initialising dp array
        int[][] dp = new int[d][n];
        
        //Base case value will be equal to first value in the array
        dp[0][0] = jobDifficulty[0];
        //Looping through the difficulty array
        for(int i = 1; i < n; i++){
            //For value of d as 0, dp value will be max of difficulty and previous dp value for each array element
            dp[0][i] = Math.max(jobDifficulty[i],dp[0][i-1]);
        }
        
        //Looping through each d
        for(int i = 1; i < d; i++){
            //Looping through difficulty array
            for(int j = i; j < n; j++){
                //Defining local max as difficulty element
                int localMax = jobDifficulty[j];
                //Initialising dp value as max integer
                dp[i][j] = Integer.MAX_VALUE;
                //Looping from j value to i value, finding local maximum with respect to difficulty array on that index, and then finding dp value as minimum of current value and (dp[i-1][r-1] + localMax).
                for(int r = j; r >= i; r--){
                    localMax = Math.max(localMax,jobDifficulty[r]);
                    dp[i][j] =  Math.min(dp[i][j],dp[i-1][r-1] + localMax);
                }
            }
        }
        
        //Returning the ans
        return dp[d-1][n-1];
    }
}
