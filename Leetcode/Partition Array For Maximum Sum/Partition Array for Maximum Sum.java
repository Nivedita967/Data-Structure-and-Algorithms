class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        //Finding the size of given array
        int size = arr.length;
        //Dp array will contain the answer for number of elements at each index i
        int[] dp = new int[size + 1];
        //Looping through the array
        for (int i = 1; i <= size; ++i) {
            //temp will store the temporary answer
            int temp= 0; 
            //loopAns will store the answer for the loop
            int loopAns = 0;
            //We will loop for each value of j from1 to k
            //Then we will store the temporary maximum and also update our loop answer
            for (int j = 1; j <= k && i - j >= 0; j++) {
                temp = Math.max(temp, arr[i - j]);
                loopAns = Math.max(loopAns, dp[i - j] + temp * j);
            }
            //Storing the value
            dp[i] = loopAns;
        }
        return dp[size];
    }
}
