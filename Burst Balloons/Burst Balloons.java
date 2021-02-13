class Solution {
    public int maxCoins(int[] nums) {
        int size= nums.length;
        if(size==0){
            return 0;
        }
        int dp[][] = new int[size][size];
        for(int n=0;n<size;n++){
            for(int i=0;i+n<size;i++){
                int j= i+n;
                for(int k=i;k<=j;k++){
                    int leftValue= i==0? 1: nums[i-1];
                    int rightValue= j==size-1?1: nums[j+1];

                    int left= k==i?0: dp[i][k-1];
                    int right= k==j?0: dp[k+1][j];

                    dp[i][j]= Math.max(dp[i][j], leftValue*nums[k]*rightValue + left+ right);
                }
            }
        }
        return dp[0][size-1];
    }
}
