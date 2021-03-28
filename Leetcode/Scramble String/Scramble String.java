class Solution {
    public boolean isScramble(String s1, String s2) {
        //If both lengths are not equal, then return false
        if (s1.length() != s2.length()){
          return false;  
        } 
        //Finding the length
		int len = s1.length();
        //Initialsing dp which will contain whether s1 is scramble of s2 or not
		boolean [][][] dp = new boolean[len][len][len + 1];
        //Loopings through strings
		for (int k = 1; k <= len; ++k)
			for (int i = 0; i + k <= len; ++i)
				for (int j = 0; j + k <= len; ++j)
                    //If k is 1, then we need to check if S1[i] and S2[j] are equal 
					if (k == 1){
                        dp[i][j][k] = s1.charAt(i) == s2.charAt(j);
                    }
                    //Else we will loop where q is a cut
					else for (int q = 1; q < k && !dp[i][j][k]; ++q) {
                        //dp value will be equal to (dp(i, j, q) AND dp(i + q, j + q, k - q)) OR (dp(i, j + k - q, q) AND dp(i + q, j, k - q))
						dp[i][j][k] = (dp[i][j][q] && dp[i + q][j + q][k - q]) || (dp[i][j + k - q][q] && dp[i + q][j][k - q]);
					}
        //Returning ans
		return dp[0][0][len];
    }
}
