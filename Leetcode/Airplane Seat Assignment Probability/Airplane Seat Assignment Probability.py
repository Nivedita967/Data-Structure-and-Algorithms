# https://leetcode.com/problems/airplane-seat-assignment-probability

class Solution:
    def nthPersonGetsNthSeat(self, n: int) -> float:
        # Each round we have 3 choices:

        # the 1st person gets his/her own seat. (with probability 1/n). Then the n-th person is sure (with probability 1) to get the n-th seat.
        
        # the 1st person gets the n-th person's seat. (with probability 1/n). Then the n-th person cannot (with probability 0) get the n-th seat.
        
        # the 1st person gets a seat between 2 and n-1 (with probability (n-2)/n). Assume the 1st person gets a-th seat. Then in the next round, we have 3 choices again:
        
        #     3.1) if the a-th person gets 1st seat (with probability 1/(n-1)), then this is just like 1st and a-th person swap their seats, it never affect our result for the n-th person.
        
        #     3.2) if the a-th person gets n-th seat (with probability 1/(n-1)), game over.
        
        #     3.3) if the a-th person gets a seat which is not 1st or n-th, (with probability (n-1-2)/(n-1)), we jump into a loop.
        
        # Therefore the dp pattern is dp[i] = 1.0 / (i+1) + 0.0 / (i+1) + dp[i-1] * (i-1) / (i+1), with dp[0]=1 for the case there's only one person. If you manually calculate it you'll find dp[i] is always 1/2 except the base condition.
        
        dp = [0] * n
        dp[0] = 1.0
        for i in range(1, n):
            dp[i] = 1.0 / (i + 1) + dp[i - 1] * (i - 1) / (i + 1)
        return dp[-1]
