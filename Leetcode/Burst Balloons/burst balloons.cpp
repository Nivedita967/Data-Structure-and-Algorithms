class Solution {
	public int maxM(int[] nums) {
		// corner case
		if(nums == null || nums.length == 0) return 0;
		
		int n = nums.length;
		int[] newNums = new int[n + 2]; // expand nums
		for(int i = 0; i < n; i++) newNums[i + 1] = nums[i];
		newNums[0] = 1;
		newNums[n + 1] = 1;
		
		// M[i, j] represents the max coins we can get for index i to j, i.e. nums[i : j] 
		int[][] M = new int[n + 2][n + 2];

		// induction rule
		// assume we keep nums[k] as the last to burst, then 
		// M[i][j](j >= i) = Math.max(M[i][j], M[i][k - 1] + nums[k - 1]*nums[k]*nums[k + 1] + M[k + 1][j])
	 
		// define the sub-problem size by the length l, we solve the all the sub-problems M[i][i + l - 1] where i varies
		for(int l = 1; l <= n; l++){
			// with fixed length l, i + l can not larger than n, i.e. i + l - 1 <= n, thus we have i <= n - l + 1
			for(int i = 1; i <= n - l + 1; i++){
				int j = i + l - 1;
				for(int k = i; k <= j; k++){
					M[i][j] = Math.max(M[i][j], M[i][k - 1] + newNums[i - 1]*newNums[k]*newNums[j + 1] + M[k + 1][j]);
				}
			}
		}
		
		return M[1][n];
	}
}
