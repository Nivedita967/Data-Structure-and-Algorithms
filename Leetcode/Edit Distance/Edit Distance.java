class Solution {
    public int minDistance(String word1, String word2) {
        //Finding size of both strings
        int m = word1.length();
        int n = word2.length();
        
        //Initialsing dp
        int[][] dp = new int[m + 1][n + 1];
        
        //If either of strings are empty, then each letter will have to be deleted/added. This is the base case
        for(int i = 0; i <= m; i++){
            dp[i][0] = i;
        }
        for(int i = 1; i <= n; i++){
            dp[0][i] = i;
        }
        
        //Looping through the strings
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                //If the characters are equal, then the operations will be same as previous operations
                if(word1.charAt(i) == word2.charAt(j))
                    dp[i + 1][j + 1] = dp[i][j];
                //If they are not equal, then we will select the cheapest operation, i.e. insert, delete or replace and that will be our ans
                else {
                    int a = dp[i][j];
                    int b = dp[i][j + 1];
                    int c = dp[i + 1][j];
                    dp[i + 1][j + 1] = a < b ? (a < c ? a : c) : (b < c ? b : c);
                    dp[i + 1][j + 1]++;
                }
            }
        }
        //Return the ans
        return dp[m][n];
    }
}
