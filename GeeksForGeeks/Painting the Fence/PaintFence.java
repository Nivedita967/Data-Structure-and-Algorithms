class Solution
{
    long countWays(int n,int k)
    {
        //code here.
        long N= 1000000007;   //for modulo

        //2 dimensional dp array 
        long [][] dp= new long[2][n];

        dp[0][0]= 0; // last 2 same
        dp[1][0]= k; // last 2 different

        //loop on complete array 
        for(int i=1; i<n; i++){
            dp[0][i]= dp[1][i-1] %N;  //when last 2 are same 
            dp[1][i]= ((( (dp[0][i-1])%N + (dp[1][i-1])%N)%N)*((k-1)%N)%N);   //when last 2 are different
        }
        
        return (dp[0][n-1] + dp[1][n-1])%N;   
    }
}
