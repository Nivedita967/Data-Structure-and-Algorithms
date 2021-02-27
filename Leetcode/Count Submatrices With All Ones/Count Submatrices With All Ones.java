class Solution {
    public int numSubmat(int[][] mat) {
        //Decalring the ans
        int ans = 0;
        //Declaring row and column length
		int m = mat.length;
		int n = mat[0].length;
		
        //For each row from 1, we will update the matrix based on if we found 0 or 1
        //If it is 1, then we will update it to its prev row value+1, otherwise 0
		for (int row = 1; row < m; row++) {
			for (int col = 0; col < n; col++) {
				mat[row][col] = mat[row][col] == 1 ? mat[row - 1][col] + 1 : 0;
			}
		}
		
        //Now while traversing, if we find a value that is not zero, we add it to ans
        //On the same row, we check every column to see if there are more 1's
		for (int row = 0; row < m; row++) {
			for (int col = 0; col < n; col++) {
				if (mat[row][col] != 0) {
					int min = mat[row][col];
					ans += min;
					for (int k = col + 1; k < n && mat[row][k] != 0; k++) {
						min = Math.min (min, mat[row][k]);
						ans += min;
					}
				}
			}
		}
		
		return ans;
    }
}
