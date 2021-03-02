/*
A java program for Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
*/

class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] < target) l = mid+1;
            else if(nums[mid] > target) r = mid-1;
            else return mid;
        }
        return l;
    }
}

/*
Sample Case:
Example 1:
Input: nums = [1,3,5,6], 
target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], 
target = 2
Output: 1
*/
