class Solution {
    public int numOfArrays(int n, int m, int k) {
        //Creating dp array
        Integer[][][] dp = new Integer[n + 1][m + 1][k + 1];
        //returning ans function's value
        return ans(n, m, k, 0, 0, 0, dp);
    }

    //Here, the current maximum element is 'currMax' and the current search cost is 'currCost'
    int ans(int n, int m, int k, int i, int currMax, int currCost, Integer[][][] dp) {
        //If current i is equal to n
        if (i == n) {
            // Return valid if the value of search cost is equal to k
            if (k == currCost){
               return 1; 
            } 
            return 0;
        }
        
        //If value of current i, current max and current cost is not equal to null in dp ans, then we return it
        if (dp[i][currMax][currCost] != null){
            return dp[i][currMax][currCost];
        }
        //Declaring temp ans
        int temp = 0;
        // Case 1: num in range [1, currMax], newMax = currMax, newCost = currCost
        temp += (long) currMax * ans(n, m, k, i + 1, currMax, currCost, dp) % 1_000_000_007;

        // Case 2: num in range [currMax+1, m], newMax = num, newCost = currCost + 1
        if (currCost + 1 <= k) {
            for (int num = currMax + 1; num <= m; num++) {
                temp += ans(n, m, k, i + 1, num, currCost + 1, dp);
                temp %= 1_000_000_007;
            }
        }
        // Returning 1 if they are equal
        return dp[i][currMax][currCost] = temp;
    }
}
