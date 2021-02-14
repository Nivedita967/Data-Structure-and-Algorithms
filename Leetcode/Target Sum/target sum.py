# Problem Link: https://leetcode.com/problems/target-sum/ 

class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        # initialize memo
        self.memo = dict()
        
        # result from recursive helper
        return self.dfs(nums, S, 0)
    
    def dfs(self, nums, S, cur):
        # check if this was stored in memo already
        # because from this point forward, we would be doing wasteful computation
        if (S, cur) in self.memo:
            return self.memo[(S, cur)]
        
        # check if cur reached end of nums
        if cur == len(nums):
            # return 1 (valid sum) if S was reduced to 0, otherwise none
            return 1 if S == 0 else 0
        
        # add both positive and negative versions of num at cur to S
        # and add results of both of those recursive subtrees
        result = (
            self.dfs(nums, S - nums[cur], cur + 1) +
            self.dfs(nums, S + nums[cur], cur + 1)
        )
        
        # store result and return it
        self.memo[(S, cur)] = result
        return result
