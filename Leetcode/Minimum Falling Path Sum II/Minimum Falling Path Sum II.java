class Solution {
    public int minFallingPathSum(int[][] arr) {
        //Finding the length of row and column and declaring ans
        int m = arr.length, n = arr[0].length,ans = Integer.MAX_VALUE; 
        //Declaring dp array
        int[][] dp = new int[m][n];
        //Traversing through each row
        for (int i = 0; i < m; i++) {
            //Filling the base case, i.e. row 0
            if (i == 0) {
                dp[i] = arr[i]; continue;
            }
            //Traversing through each column
            for (int j = 0; j < n; j++) {
                //Initialising the value as maximum
                dp[i][j] = Integer.MAX_VALUE;
                //Traversing again through the columns
                for (int k = 0; k < n; k++) {
                    //If both indices are not equal, then the value of current dp will be minimum of max value and sum of current array value and previous row value
                    if (j != k){
                      dp[i][j] = Math.min(dp[i][j], arr[i][j] + dp[i - 1][k]);  
                    }
                }
                //If i reaches the end, then answer will be minimum of dp value and current ans value
                if (i == m - 1){
                 ans = Math.min(ans, dp[i][j]);   
                }
            }
        }
        return ans;
    }
}
