"""
A python program to implement Stone Game
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.
Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.
Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

"""

class Solution(object):
    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        if len(piles) % 2 ==0 or len(piles) == 1:
            return True
        
        dp = [0] * len(piles);
        for i in reversed(xrange(len(piles))):
            dp[i] = piles[i]
            for j in xrange(i+1, len(piles)):
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j-1])
        return dp[-1] >= 0 
      
"""
Sample Input/Output
Example 1:
Input: piles = [5,3,4,5]
Output: true

"""
