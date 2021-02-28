#91. Decode Ways
#https://leetcode.com/problems/decode-ways/
    
class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0
        
        # count the number of ways to decode s[:i]
        
        dp = [0 for x in range(len(s) + 1)]
        dp[0:2] = [1, 1]
        for i in range(2, len(s) + 1):
            # One step jump
            if 0 < int(s[i - 1]):
                dp[i] = dp[i - 1]
            # Two step jump
            if 10 <= int(s[i - 2 : i]) <= 26:
                dp[i] += dp[i - 2]
        return dp[-1]
