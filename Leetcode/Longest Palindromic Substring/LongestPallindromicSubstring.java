class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        int max_=0;
        int[][] dp = new int[n][n];

        // using th gap method
        for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; i++, j++){
                // Case 1: when gap = 0
                if(i==j){
                    dp[i][j] = 1;
                }
                // Case 2: when gap = 1
                else if(s.charAt(i) == s.charAt(j) && gap == 1){
                    dp[i][j] = 2;
                }
                // Case 3: when extreme characters are same
                else if(s.charAt(i) == s.charAt(j)){
                    if(dp[i+1][j-1]==0){
                        dp[i][j]=0;
                    }
                    else 
                    dp[i][j] = dp[i+1][j-1] +2;
                }
                // Case 4: when extreme characters are different
                else{
                    dp[i][j] = 0;
                }
                
                // storing maximum value to get the longest
                max_= Math.max(max_, dp[i][j]);
            }
        }
        for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; i++, j++){
                if(dp[i][j]==max_){
                    return s.substring(i, j+1);
                }
            }
        }
        return "";
    }
}