# A program to find number of ways to paint a given grid by 3 colours

class Solution(object):
    def numOfWays(self, n):         # Defining a function to calculate number of ways

        mod = 10**9+7               # Declaring a variable to store the number to which modulus is taken
        dp = [[6, 6] for _ in range(n)]
        for i in range(1, n):
            dp[i][0] = 2*dp[i-1][0] + 2*dp[i-1][1]
            dp[i][1] = 2*dp[i-1][0] + 3*dp[i-1][1]
            dp[i][0] %= mod         # Storing modulus to the 2D array
            dp[i][1] %= mod
        return sum(dp[n-1])%mod
 
s=Solution()
print(s.numOfWays(7))               # Calculating number of ways and printing it
