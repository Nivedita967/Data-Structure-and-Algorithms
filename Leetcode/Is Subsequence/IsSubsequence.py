class Solution:
    # s-> string to be find
    # t-> input string
    def isSubsequence(self, s: str, t: str) -> bool:
        j = 0
        # return true if s is empty
        if len(s) < 1:
            return True

        # we will compare all the alphabets of s and t in order
        for i in range(len(t)):
            # if the characters match then only we'll increment j index.
            if s[j] == t[i]:
                j += 1

            # if j is not reached til the end of string s that would mean, all characters of s are not present in t or they are not in order.
            # and if j is equal to length of s it is subsequence of t
            if j == len(s):
                return True
        else:
            return False


