# https://leetcode.com/problems/trapping-rain-water/

# Approach :
# It can be seen that the amount of water above a point (X) depends on the heights of the highest bars to the left and right of it, regardless of how far apart they are.  
# The height of the water above it is equivalent to the minimum height of the highest bars around it.  
# Water can be calculated water=minimum(left_max, right_max) - elevation_X
# Consider using two pointers, one from the left and then one from the right to find the local maxima at each index.  From there we should be able to calculate the volume of water at each stage.  
# Traverse the list once, calculate the left_max for each point and save it in a list
# Travserse again to do the same with right_max.  
# Traverse once more to use this data and find the amount of water above each point.

class Solution:
     def trap(self, height: List[int]) -> int:
         # keep track of the total water as we traverse the heights
         water = 0
        
         # number of x-values on height chart
         n = len(height)
        
         # lists to store the left_max and right_max at each point in the chart
         left_max = [0] * n
         right_max = [0] * n
        
         # default values
         left_max[0] = height[0]
         right_max[n - 1] = height[n - 1]
        
         # filling in the left_max list
         for i in range(1, n):
             left_max[i] = max(left_max[i - 1], height[i])
            
         # filling in the right max list
         for i in range(n - 2, -1, -1):
             right_max[i] = max(right_max[i + 1], height[i])
            
         # calculating the amount of water
         for i in range(n):
             water += min(left_max[i], right_max[i]) - height[i]
            
         return water
