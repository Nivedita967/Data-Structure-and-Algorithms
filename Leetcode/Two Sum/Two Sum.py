"""
A python program to implement Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

"""

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        container = {}
        
        for i, num in enumerate(nums):
            if target - num in container:
                return [container[target - num], i]
            container[num] = i
        return
        
"""
Sample input/output :
Example 1:
Input: nums = [2,7,11,15],
target = 9
Output: [0,1]

Example 2:
Input: nums = [3,2,4],
target = 6
Output: [1,2]

"""
