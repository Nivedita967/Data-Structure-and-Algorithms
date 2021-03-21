"""
A peak element is an element that is strictly greater than its neighbors.
Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks
, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞.

"""
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if nums == None or len(nums) == 0:
            return -1
        return self.helper(0, len(nums) - 1, nums)
        
    def helper(self, st, end, nums):
        mid = (st + end) // 2 # Find the mid index
        if mid > 0 and nums[mid] < nums[mid - 1]: # if nums[mid-1] is the hill
            return self.helper(st, mid-1, nums) # recursion: for left side of mid
        elif mid < len(nums)-1 and nums[mid] < nums[mid + 1]: # if nums[mid+1] is the hill
            return self.helper(mid+1, end, nums) # recursion: for right side of mid
        else:
            return mid # if nums[mid] is the hill