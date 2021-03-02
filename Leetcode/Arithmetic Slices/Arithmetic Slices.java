class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        //This will keep the current count
        int count = 0; 
        //Declaring final ans
        int ans = 0;
        //Traversing the array and if we find three consecutive elements with same difference, we increase the count, else if we reinitialise count
        for (int i=2; i<nums.length; i++){
        if (nums[i]-nums[i-1] == nums[i-1]-nums[i-2]) {
            count += 1;
            ans += count;
        } 
        else {
            count = 0;
        }
        }
        //Returning the ans
        return ans;
    }
}
