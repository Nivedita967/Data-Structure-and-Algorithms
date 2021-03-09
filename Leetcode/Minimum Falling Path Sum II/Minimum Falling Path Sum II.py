#Problem: https://leetcode.com/problems/minimum-falling-path-sum-ii/

import heapq

class Solution(object):
    def minFallingPathSum(self, arr):
        n = len(arr)

        for row in range(1, n):
             
            # For each row, only the smallest and second smallest paths are used.
            smallest, second = heapq.nsmallest(2, arr[row - 1])
            # Iterate over the rows, updating each element with the minimum sum path.
           # For each row, each column is incremented by the smallest path from the previous row if the smallest path from
            # the previous row is not the smallest, else is incremented by the second smallest path from the previous row
            for col in range(n):
                arr[row][col] += second if arr[row - 1][col] == smallest else smallest

        return min(arr[-1])
