class Solution {
    public int searchInsert(int[] nums, int target) {
        int i=0;
        for(; i<nums.length && nums[i]<target; i++)
        return i;
    }
}