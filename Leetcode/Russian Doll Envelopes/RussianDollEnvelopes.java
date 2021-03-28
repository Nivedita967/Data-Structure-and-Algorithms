class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        //sorting the array on basis of first entity i.e. height of envelope
        Arrays.sort(envelopes, (a, b) -> Integer.compare(a[0], b[0]));

        //taking LIS of the sorted array on the basis of second entity i.e. width of envelope.
        //By this we can ensure we get both height and width of envelopes in strictly increasing order so as to fit in the maximum envelopes
        int[] dp = new int[envelopes.length];
        Arrays.fill(dp, 1);
        int max_=1;
        for(int i=1; i<envelopes.length; i++){
            for(int j=i-1; j>=0; j--){
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1]< envelopes[i][1]){
                    dp[i]= Math.max(dp[i], dp[j]+1);
                }
            }
            max_= Math.max(max_, dp[i]);
        }
        return max_;
    }
}