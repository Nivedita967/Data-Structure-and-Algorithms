class Solution{
    // function to find LCS
    static int lcs(int p, int q, String s1, String s2){
        // your code here
        int [][] dp = new int[s1.length()+1][s2.length()+1];

        // each cell of dp array stores a new possible lcs
        for(int i=1; i<=s1.length(); i++){
            for(int j=1; j<=s2.length(); j++){

                // case 1 : when the two end characters are alike 
                if(s1.charAt(i-1) == s2.charAt(j-1)){
                    dp[i][j]= dp[i-1][j-1] + 1;
                }

                // case 2 : when two end characters are different
                else{
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
}