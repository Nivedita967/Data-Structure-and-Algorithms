#Problem:https://leetcode.com/problems/wildcard-matching/
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n = len(s) # row
        m = len(p) # column
        
        # dynamic programming table initialization
        
        dp = [ [False for i in range(m+1)] for j in range(n+1) ]
        
        # if both the text and the pattern is an empty string then it's a match
        dp[0][0] = True
        
        # this is for the 0th row where a kleene star can take 0 or any sequence of characters
        # hence we look at the cell to the left
        
        for i in range(1, m+1):
            if p[i-1] == '*':
                dp[0][i] = dp[0][i-1]
        
        for i in range(1, n+1):
            for j in range(1, m+1):
                # direct match hence we look at the cell diagonally above
                # if the substring is a match without the character then it is also
                # a match for the given string
                
                if s[i-1] == p[j-1] or p[j-1] == '?':
                    dp[i][j] = dp[i-1][j-1]

                # hence we look at the cell to the left and at top
                # if either of the cells return True then the string is a match
                # this is because we need to consider the 0th occurance -> cell to the left
                # and also any number of sequence -> cell at the top
                if p[j-1] == '*':
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]
         
        return dp[-1][-1]  # this returns the last cell which has the answer
