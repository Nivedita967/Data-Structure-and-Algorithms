class Solution {
    public int fib(int N) {
        int[] dp= new int[N+1];
        dp[0]=0;
        for(int i=1; i<=N; i++){
            if(i==1){
                dp[i]= 1;
            }
            else{
                dp[i]= dp[i-1]+dp[i-2];
            }
        }
        return dp[N];
    }
}