class Solution {
    public int minInsertions(String s) {
        //Finding the size of given string
        int n = s.length();
        //Initialising dp array. It will represent the longest common subsequence between first i characters of first string and first j characters of second string
        int[][] dp = new int[n+1][n+1];
        
        //Looping through start and end of the string. Thus dp will consider the string from start and string from end and then store the ans
        for (int i = 0; i < n; ++i){
          for (int j = 0; j < n; ++j){
              
              //If both the characters are equal, then we increment the previous dp value otherwise we take max of the next character considered for both strings
              dp[i + 1][j + 1] = s.charAt(i) == s.charAt(n - 1 - j) ? dp[i][j] + 1 : Math.max(dp[i][j + 1], dp[i + 1][j]);
          }  
        }
        //Returning ans
        return n - dp[n][n];
    }
}
