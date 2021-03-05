#1402 Reducing Dishes
#Problem:https://leetcode.com/problems/reducing-dishes/
        
from typing import List


class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        #Sort the satisfaction list in increasing order
        satisfaction.sort()
        total, cur, result,  n = 0, 0, 0,  len(satisfaction)
        #Sum of all satisfaction levels
        for i in range(n):
            total += satisfaction[i]  
        #Calculate the current position of like time coefficient
        while total < 0 and cur < n:
            total -= satisfaction[cur]
            cur += 1
        #Calculate the total sum of like time coefficient
        for i in range(cur, n):
            result += (i-cur+1)*satisfaction[i]
        return result
