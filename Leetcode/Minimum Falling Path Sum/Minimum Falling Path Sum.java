class Solution {
    public int minFallingPathSum(int[][] matrix) {
        //The minimum falling path sum for a position (i,j) will be minimum of A[i - 1][j - 1], A[i - 1][j] and A[i - 1][j + 1]
        //So we start filling the matrix from row 1 and then return the minimum sum
        for (int i = 1; i < matrix.length; ++i){
            for (int j = 0; j < matrix.length; ++j){
                matrix[i][j] += Math.min(matrix[i - 1][j], Math.min(matrix[i - 1][Math.max(0, j - 1)], matrix[i - 1][Math.min(matrix.length - 1, j + 1)]));
            }
        }
  return Arrays.stream(matrix[matrix.length - 1]).min().getAsInt();
    }
}
