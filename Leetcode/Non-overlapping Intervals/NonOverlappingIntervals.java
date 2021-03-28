class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        //sorting the intervals array based on first value
        Arrays.sort(envelopes, (a, b) -> Integer.compare(a[0], b[0]));

        int[] dp = new int[envelopes.length];
        Arrays.fill(dp, 1);

        // calculating LIS on the basis of second value in order to cover maximum no of intervals
        int max_=1;
        for(int i=1; i<envelopes.length; i++){
            for(int j=i-1; j>=0; j--){

                //including intervals to our answer only when we get start time of current < ending time of previous in order to avoid intersection
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1]< envelopes[i][1]){
                    dp[i]= Math.max(dp[i], dp[j]+1);
                }
            }

            //calculating maxlength of dp .
            max_= Math.max(max_, dp[i]);
        }
        return max_;
    }
}