"""
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

"""
class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        sum = 0 # Initialize sum to 0
        for i in range(len(nums)):
            sum = sum + nums[i] # runningSum[i] = sum(nums[0]…nums[i])
            nums[i] = sum # replacing previous nums[i] with runningSum from 0 index till i index
        return nums # return the nums array containing the running sum