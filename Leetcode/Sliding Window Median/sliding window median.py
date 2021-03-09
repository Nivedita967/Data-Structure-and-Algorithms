#480. Sliding Window Median
#https://leetcode.com/problems/sliding-window-median/
class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        even = (k % 2 == 0)

        def median(even, nums, r, l):
            #Sort the array for selected window elements from left to right +1
            n = sorted(nums[l:r + 1])
            if even:
                #Pick average of 2 middle values
                med = (n[(k // 2) - 1] + n[k // 2]) / 2
            else:
                #When array odd pick middle value 
                med = n[k // 2]
            return med

        #Set position for left and right as zero for k elements of sliding window 
        r = 0
        l = 0
        ans = []
        #Iterate till we reach end of list
        while r < len(nums):
            #select k elements till it reaches k
            if r - l + 1 == k:
                 #Add median value for every slicing window till it reaches k slicing windows 
                ans.append(median(even, nums, r, l))
                l += 1
            r += 1
        return ans
