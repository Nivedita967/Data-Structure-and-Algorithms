# A Program to find number of characters to be changed to make subsrting of a string palindrome


class Solution:
    def palindromePartition(self, s: str, k: int) -> int:      # Checking length of the partition
        if len(s) <= k or s == "":
            return 0
        if len(s) == 1:
            return 1
        
        def minChangePalandrome(s):                            # Calculating minimum change to be done to make it palindrome
            cnt = 0
            n = len(s)
            
            for i in range(int(n/2)):
                if s[i] != s[n-i-1]:
                    cnt += 1
            
            return cnt                                          # Returning result
        
        n = len(s)
        dp = [[float("inf")] * k for _ in range(n)]
        
        dp[0][0] = minChangePalandrome(s[0])                
        
        for i in range(1, len(s)):
            dp[i][0] = minChangePalandrome(s[0:i+1])
        
        for i in range(n):
            for d in range(1, min(i + 1, k)):
                for l in range(i):
                    dp[i][d] = min(dp[i][d], dp[l][d-1] + minChangePalandrome(s[l+1:i+1]))

        return dp[-1][-1]
