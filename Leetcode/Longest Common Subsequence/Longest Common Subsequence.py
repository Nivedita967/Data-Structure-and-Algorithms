"""
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3 

Example: 2
Input: text1 = "abc", text2 = "abc"
Output: 3

"""
class Solution:
    # First initialize the grid dp then add an empty character to the texts which would account for 0 value.
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[0 for i in range(len(text2) + 1)] for j in range(len(text1) + 1)]
        text1 = " " + text1 
        text2 = " " + text2
        
        for i in range(1, len(text1)):
            for j in range(1, len(text2)):
                # Whenever we have two matching character the result will be 1 + (value of dp[row-1][col-1])
                if text1[i] == text2[j]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    # Whenever the characters do not match then the result will be the max of values dp[row][col] =  max(dp[row-1][col],dp[row][col-1])
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            # the dp[last Row][last col] would be the length of longest common subsequence.
        return dp[-1][-1]