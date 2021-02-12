class Solution {
    public int maxSubArray(int[] nums) {
        int max_ending_here = nums[0];
        int max_so_far = nums[0];
        for (int i = 1; i < nums.length; i++) {
            max_ending_here += nums[i];
            if (max_ending_here < nums[i])
                max_ending_here = nums[i];
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;

        }
        return max_so_far;
    }
}