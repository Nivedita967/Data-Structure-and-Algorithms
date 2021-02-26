/*Idea: The most standard solution to this question is dp;

dp[i,j] = Max(arr[i....k]) * Max(arr[k+1, j]) + dp[i, k] + dp[k+1, j];
*/
class Solution {
    public int mctFromLeafValues(int[] arr) {
        if(arr == null || arr.length == 0) {
            return 0;
        }
        
        int n = arr.length;
        int[][] dp = new int[n][n];
        int[][] maxarr = new int[n][n];
        for(int i = 0; i < n; i++) {
            int localmax = 0;
            for(int j = i; j < n; j++) {
                if(arr[j] > localmax) {
                    localmax = arr[j];
                }
                maxarr[i][j] = localmax;
            }
        }
        
        for(int len = 1; len < n; len++) {
            for(int i = 0; i + len < n; i++) {
                int j = i + len;
                dp[i][j] = Integer.MAX_VALUE;
                if(len == 1) {
                    dp[i][j] = arr[i] * arr[j];
                } else {
                     for(int k = i; k < j; k++) {
                        dp[i][j] = Math.min(dp[i][j], 
                                          maxarr[i][k] * maxarr[k+1][j] + dp[i][k] + dp[k+1][j]);
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
}
