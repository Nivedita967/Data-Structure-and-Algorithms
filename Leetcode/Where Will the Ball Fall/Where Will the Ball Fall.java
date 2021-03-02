class Solution {
    public int[] findBall(int[][] grid) {
        //Finding columns, rows and declaring ans
        int m = grid.length;
        int n = grid[0].length; 
        int ans[] = new int[n];
        //Traversing through each column
        for (int i = 0; i < n; ++i) {
            int i1 = i, i2;
            //Traversing through each row
            for (int j = 0; j < m; ++j) {
                i2 = i1 + grid[j][i1];
                //If i2 is invalid or if the ball gets stuck
                if (i2 < 0 || i2 >= n || grid[j][i2] != grid[j][i1]) {
                    i1 = -1;
                    break;
                }
                i1 = i2;
            }
            ans[i] = i1;
        }
        return ans;
    }
}
