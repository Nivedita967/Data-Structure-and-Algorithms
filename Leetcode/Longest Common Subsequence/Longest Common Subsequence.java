class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        //If either of the strings are empty, then length of LCS will be 0
        if(text1.length()==0||text2.length()==0){
            return 0;
        }
        //Creating dp array for each possibility of length
        int dp[][] = new int[text1.length()+1][text2.length()+1];
		
        //Looping through all possibilities
        for(int i=1;i<text1.length()+1;i++){
            for(int j=1;j<text2.length()+1;j++){
                //If character matches, then add 1 to the previous answer
                if(text1.charAt(i-1)==text2.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                //If doesn't match, then skip
                else{
                    dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //Returning final answer
        return dp[text1.length()][text2.length()];
    }
}
