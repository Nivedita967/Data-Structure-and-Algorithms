class Solution {
    public int uniquePaths(int m, int n) {
        //Initialising dp array
        Integer[][] dp = new Integer[m][n];
        //If n=0,then dp value will be 1
        for(int i = 0; i<m;i++){
            dp[i][0] = 1;
        }
        //If m=0,then dp value will be 1
        for(int j= 0;j<n;j++){
            dp[0][j]=1;
        }
        //For all the other points, ans will be sum of up and left point ans
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        //Return the final ans
        return dp[m-1][n-1];
    }
}
