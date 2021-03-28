"""
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

"""

class Solution:
    def minDistance(self, word1, word2):
        s1, s2 = len(word1), len(word2)  #Calculate length of word1 & word2 for forming dp grid
        dp = [[0 for _ in range(s2+1)] for _ in range(s1+1)] # Form a grid corresponding to length of strings
        # Here n & m are the length of the strings
        def helper(n, m):
            # If there is no character in word1 then to make it word2, len(word2) characters needs to be added.
            if n==0:
                return m
             # If there is no character in word2 then to make word1 equal to word2, len(word1) characters needs to be deleted.
            if m==0:
                return n
            if dp[n][m]:
                return dp[n][m]
            # If the last charcter are equal then run resursive for n-1,m-1 value
            if word1[n-1] == word2[m-1]:
                dp[n][m] = helper(n-1, m-1)
                return dp[n][m]
            # [helper(n-1, m): Delete a charcater], [helper(n-1, m-1): Subtitution], [helper(n, m-1): Addition]
            ans = 1 + min(helper(n, m-1), helper(n-1, m-1), helper(n-1, m))
            dp[n][m] = ans
            return ans
        
        return helper(s1, s2)

    