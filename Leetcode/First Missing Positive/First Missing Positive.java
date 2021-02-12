class Solution {
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        int i = 1;
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] == i) {
                i++;
            }
        }
        return i;

    }
}