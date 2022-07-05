class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        j = 0
        if len(s) < 1:
            return True
        for i in range(len(t)):
            if s[j] == t[i]:
                j += 1
            if j == len(s):
                return True
        else:
            return False


