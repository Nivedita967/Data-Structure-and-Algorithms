class Solution {
    public int countSubstrings(String s) {
        //Finding the length of given string
        int n = s.length();
        //Initialising answer
        int ans = 0;
        //dp array will contain answer for if a string with starting at i and ending at j is a palindrome
    boolean[][] dp = new boolean[n][n];
        //We will start traversing from the end. For each i, we will calculate the answer for all j greater than or equal to i but less than the string length
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            //If the character at i and j is equal, then we need to check two cases:
            //Case 1: It is a single letter or two letters. For those conditions we have checked j-i+1<3
            //Case 2: If the string between the i and j position, i.e. the string starting at i+1 and ending at j-1 is a palindrome
            dp[i][j] = s.charAt(i) == s.charAt(j) && (j - i  + 1 < 3 || dp[i + 1][j - 1]);
            if(dp[i][j]){
                ans++;
            } 
        }
    }
    return ans;
    }
}
