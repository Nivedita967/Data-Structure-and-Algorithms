from collections import Counter
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        c = Counter(nums)
        for n in c.keys():
            if c[n] == 1:
                return n
              
'''
Example 1:

Input: nums = [2,2,1]
Output: 1
----------------------
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
'''
