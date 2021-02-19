class Solution {
    public int[][] matrixBlockSum(int[][] mat, int K) {
        //Finding the sizes of rows and columns
        int m = mat.length;
        int n = mat[0].length;
        //This matrix will contain our answer
        int[][] ans = new int[m][n];
        //This matrix will contain prefix sums
        int[][] prefix = new int[m][n];
        //Calculating prefix sums for every i and j
        for(int i = 0; i < m; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                sum += mat[i][j];
                prefix[i][j] = sum;
            }
        }
        //Now, we will calculate valid range of rows and columns first
        //Then we add prefix sums to answer for row range and column's upper bound
        //And if column's lower bound is not 0, we substract those prefix sums
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                //Finding upper and lower bound for rows
                int r1 = Math.max(0, i - K);
                int r2 = Math.min(m - 1, i + K);
                //Finding upper and lower bounds for columns
                int c1 = Math.max(0, j - K); 
                int c2 = Math.min(n - 1, j + K);
                //Finding answer matrix
                for(int p = r1; p <= r2; p++) {
                    ans[i][j] += prefix[p][c2];
                    if(c1 != 0) {
                        ans[i][j] -= prefix[p][c1 - 1];
                    }
                }
            }
        }
        return ans;
    }
}
