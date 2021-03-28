"""
Given an array of integers, find the subset of non-adjacent elements with the maximum sum. 
Calculate the sum of that subset. It is possible that the maximum sum is , the case when all elements are negative.

"""

def maxSubsetSum(arr):
    
    n = len(arr) # n = length of the array
    dp = [0]*n   # create a dp array of length n & initialize its values to 0
    dp[0] = arr[0] # base
    dp[1] = max(arr[1], dp[0]) 
    
    for i in range(2,n):
       # Because of the condition. No two adjacent elements can be picked. 
       # Therefore we can either take one and then skip one, or skip one and run the subroutine.
        dp[i] = max(arr[i], dp[i-1], arr[i] + dp[i-2])
    # in the dp, we store the max sum for the subarray up till the length of the subarray.
    #  Hence simply return the last item in this to get the answer
    return dp[-1]
