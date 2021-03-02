class Solution {
    public int minPathSum(int[][] grid) {
        
        int[][] dp = new int[grid.length][grid[0].length];
        
        for(int row = dp.length - 1; row >= 0; row--) {
            for(int col = dp[0].length - 1; col >= 0; col--) {
                // bottom rightmost cell i.e. destination. Nothing to do here. Just add the value of the current cell from grid
                if(row == dp.length - 1 && col == dp[0].length - 1) {
                    dp[row][col] = grid[row][col];
                }
                // last row - Can only add the value of the adjacent right cell to the current cell from grid
                else if (row == dp.length - 1) {
                    dp[row][col] = dp[row][col + 1] + grid[row][col];
                }
                // last column - Can only add the value of the adjacent bottom cell to the current cell from grid
                else if (col == dp[0].length - 1) {
                    dp[row][col] = dp[row + 1][col] + grid[row][col]; 
                }
                // Get the min between adjacent right cell and bottom cell and add the value of the current cell from grid.
                else {
                    dp[row][col] = Math.min(dp[row + 1][col], dp[row][col + 1]) + grid[row][col];
                }
            }
        }
        
        return dp[0][0];
    }
}
