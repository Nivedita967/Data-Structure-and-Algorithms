#Python program for the jump game program in leetcode
class Solution(object):
    def maxJumps(self, arr, d):
        """
        :type arr: List[int]
        :type d: int
        :rtype: int
        """
        #new array stores sorted arr
        new_arr = sorted([(val, i) for i, val in enumerate(arr)])
        dp = [1]*len(new_arr)
        for _, i in new_arr: 
            # search towards to right
            for j in range(i+1, i+d+1): 
                if not(0<=j<len(new_arr)) or arr[j]>= arr[i]: 
                    break
                dp[i] = max(dp[i], 1 + dp[j]) 
            # search towards to left
            for j in reversed(range(i-d, i)): 
                if not(0<=j<len(new_arr)) or arr[j]>= arr[i]: 
                    break
                dp[i] = max(dp[i], 1 + dp[j]) 

        #return result  
        return max(dp)

