"""
A python program to implement Closest Dessert Cost

You would like to make dessert and are preparing to buy the ingredients. You have n ice cream base flavors and m types of toppings to choose from. You must follow these rules when making your dessert:
There must be exactly one ice cream base.
You can add one or more types of topping or have no toppings at all.
There are at most two of each type of topping.

"""

class Solution(object):
    def closestCost(self, baseCosts, toppingCosts, target):
        """
        :type baseCosts: List[int]
        :type toppingCosts: List[int]
        :type target: int
        :rtype: int
        """
        max_count = 2
        def backtracking(toppingCosts, i, cost, target, lookup, result):
            if (i, cost) in lookup:
                return
            lookup.add((i, cost))
            #  If we have reached the end of the top array
            if cost >= target or i == len(toppingCosts):
                if (abs(cost-target), cost) < (abs(result[0]-target), result[0]):
                    result[0] = cost
                return
            for j in xrange(max_count+1):
                # Recursion
                backtracking(toppingCosts, i+1, cost+j*toppingCosts[i], target, lookup, result)

        result = [float("inf")]
        lookup = set()
        for b in baseCosts:
            # For Each element of base array run DFS in the top array to find the cost.
            backtracking(toppingCosts, 0, b, target, lookup, result)
        # closest possible cost of the dessert to target    
        return result[0]
      
"""
Sample Input/Output:
Example 1:
Input: baseCosts = [1,7], toppingCosts = [3,4], target = 10
Output: 10
Example 2:
Input: baseCosts = [2,3], toppingCosts = [4,5,100], target = 18
Output: 17

"""
