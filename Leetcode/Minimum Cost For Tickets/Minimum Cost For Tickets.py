"""
A python program to implement Minimum Cost For Tickets
In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.
Train tickets are sold in 3 different ways:
a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

"""

class Solution(object):
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
        durations = [1, 7, 30]
        W = durations[-1]
        dp = [float("inf") for i in xrange(W)]
        dp[0] = 0
        last_buy_days = [0, 0, 0]
        for i in xrange(1,len(days)+1):
            dp[i%W] = float("inf")
            for j in xrange(len(durations)):
                while i-1 < len(days) and \
                      days[i-1] > days[last_buy_days[j]]+durations[j]-1:
                    last_buy_days[j] += 1  # Time: O(n)
                dp[i%W] = min(dp[i%W], dp[last_buy_days[j]%W]+costs[j])
        return dp[len(days)%W]
      
"""
Sample Input/Output:
Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11

Example 2:
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17

"""
