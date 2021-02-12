class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap();
        int complement;
        int size = nums.length;
        int[] ans = new int[2];
        for (int i = 0; i < size; ++i) {
            complement = target - nums[i];
            if (map.containsKey(complement)) {
                ans[0] = i;
                ans[1] = map.get(complement);
                return ans;
            } else {
                map.put(nums[i], i);
            }
        }
        return ans;
    }
}
