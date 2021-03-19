class Solution {
    public int maxJumps(int[] arr, int d) {
        //Finding length of the array
        int len = arr.length;
        //Creating dp array
        int[] dp = new int[len];
        //Filling the array initially with -1
        Arrays.fill(dp, -1);
        //Initialising ans
        int ans = 0;
        //For each length, finding the maximum indices using helper function
        for(int i = 0; i < len; i++) {
            ans = Math.max(ans, 1+helper(arr, dp, i, d));
        }
        //Returning ans
        return ans;
    }
    
    public int helper(int[] arr, int[] dp, int i, int d) {
        //If the value of dp is not -1, then return that value
        if(dp[i] != -1){
            return dp[i];
        }
        //Initialising the value to 0
        dp[i] = 0;
        //We consider both the cases, if we jump left first or if we jump right first. We find maximum ans for both and then take maximum of both values in order to reach our final ans
        for(int j=1; j <= d && i-j >= 0; j++) {
            if(arr[i-j] >= arr[i]){
               break; 
            }
            dp[i] = Math.max(dp[i], 1+helper(arr, dp, i-j, d));
        }
        for(int j=1; j <= d && i+j < arr.length; j++) {
            if(arr[i+j] >= arr[i]){
                break;
            }
            dp[i] = Math.max(dp[i], 1+helper(arr, dp, i+j, d));
        }
        //Returning the value
        return dp[i];
    }
}
