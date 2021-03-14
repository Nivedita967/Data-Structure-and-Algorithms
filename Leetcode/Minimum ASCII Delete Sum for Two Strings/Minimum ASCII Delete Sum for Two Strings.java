class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        // Finding the lengths of both strings
        int m = s1.length();
        int n = s2.length();
        //Initialising dp array. This will contain the answer for each m and n
        int[][] dp = new int[m+1][n+1];
        //Looping through each case
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                //If either of the strings is empty, then we will have to delete the other string to make them equal
                if(i==0 || j==0){
                    int a = 0;
                    for(int z=1;z<=Math.max(j,i);z++){
                        a += (i==0?s2.charAt(z-1):s1.charAt(z-1));
                    }
                    dp[i][j] = a;
                }
                //If both the last characters are same, then we can skip that character and answer will be equal to that of length-1
                else if(s1.charAt(i-1)==s2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                }
                //If none of case applies, then we have three options, either delete the last character of first string, or delete the last character of second string, or delete last character from both of them. We will then use minimum value of ASCII sum to find our answer
                else{
                    dp[i][j] = Math.min(s1.charAt(i-1)+dp[i-1][j],s2.charAt(j-1)+dp[i][j-1]);
                    dp[i][j] = Math.min(dp[i][j],s1.charAt(i-1)+s2.charAt(j-1)+dp[i-1][j-1]);
                }
            }
        }
        return dp[m][n];
    }
}
