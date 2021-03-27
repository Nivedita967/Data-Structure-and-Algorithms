class Solution {
    //defining mod value
    long mod = (long)1e9 + 7;
    public int numMusicPlaylists(int N, int L, int K) {
        //Creating dp array
        long[][] dp = new long[N + 1][L + 1];
        
        //Looping from K+1 to N different songs
        for (int i = K + 1; i <= N; ++i){
            //Looping from value of i and the L songs she wants to listen to
            for (int j = i; j <= L; ++j){
                //If their values are equal or if i is K+1, then number of playlists will be factorial of i
                if ((i == j) || (i == K + 1)){
                    dp[i][j] = factorial(i);
                }
                //Otherwise we can put any song at the end of music list,but it should be different from K last song
                else{
                    dp[i][j] = (dp[i - 1][j - 1] * i + dp[i][j - 1] * (i - K))%mod;
                }
            }
        }
        //Returning the ans
        return (int) dp[N][L];
    }

    //Factorial function that calculates factorial of a number
    long factorial(int n) {
        return n > 0 ? factorial(n - 1) * n % mod : 1;
    }
}
