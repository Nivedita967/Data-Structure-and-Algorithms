class Solution {
    public int longestPalindromeSubseq(String s) {
        //Finding size of the string
        int size= s.length();
        //Initialising dp array
        int[][] dp = new int[size][size];
        //Looping through characters
        for (int i = size - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j < size; j++) {
                //If characters are equal, the answer will be 2 characters+ the remaining middle string
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } 
                //If not, then they will be maximum of previous substring and next substring
                else {
                    dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        //Returning the answer
        return dp[0][size-1];
    }
}
