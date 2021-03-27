class Solution
{
    long countPS(String str)
    {
        // Your code here
        int n= str.length();
        long N = 1000000007;
        long[][] dp = new long[n][n];

        //Using gap method we store at each cell the count of Pallindromic Subsequences
        for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; i++, j++){

                // Case 1: when gap = 0
                if(gap == 0){
                    dp[i][j]= 1;
                }
                // Case 2: when gap !=0
                else{

                    //Subcase 1 : when two extreme characters are same
                    if(str.charAt(i) == str.charAt(j)){
                        dp[i][j] = (( dp[i+1][j] % N) + ( dp[i][j-1] % N) + 1 ) % N;
                    }
                    //Subcase 2 : when two extreme characters are different
                    else{
                        dp[i][j] = (( dp[i+1][j] % N) + ( dp[i][j-1] % N) - ( dp[i+1][j-1] % N) + N) % N;
                    }
                }
            }
        }
        //Returning top right cell answer
        return dp[0][n-1] % N;
    }
}