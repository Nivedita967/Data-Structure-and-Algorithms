class Solution {
    public int distinctSubseqII(String S) {
        int[] dp = new int[S.length()+1];

        // Last visited of each character
        int[] lastidx= new int[26];
        Arrays.fill(lastidx, -1);
        int n= S.length();

        // empty subsequence is only 1
        dp[0]=1;

        // for taking modulo
        int N = 1_000_000_007;
        for(int i=1; i<=S.length() ; i++){
            
            // for each character the dp is equal to twice of dp of previous character (including duplicates if any)
            dp[i]=  (2 * dp[i-1]) % N;
            if(lastidx[S.charAt(i-1)-'a'] != -1){

                // if the character occured before as well, then in order to remove duplicates subtract those values
                int idx = lastidx[S.charAt(i-1)-'a'] - 1;
                dp[i] -= dp[idx];
                dp[i] = dp[i] %N;
            }

            // Always update the last occurence of every character
            lastidx[S.charAt(i-1)-'a']=i;
        }

        // In order to handle negative values in dp array we take modulo
        if(dp[n] < 0) dp[n]+=N;
        return (dp[S.length()]) -1;
    }
}