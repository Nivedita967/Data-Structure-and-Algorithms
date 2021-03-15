"""
Problem Statement:
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
"""

class Solution:
    def decodeString(self, s: str) -> str:
        l = []
        
        
        i=0
        while (i< len(s)):
            
            if s[i] != "]":
                l.append(s[i])
            else:
                t=""
                while (l[-1]!="["):
                    t =l.pop(-1)+t
                l.pop(-1) # poppping "["
                
                n=""
                while (l and l[-1].isnumeric()):
                    n= l.pop(-1)+n
                
                t= t*int(n)
                l.append(t)
            i+=1
            
        # print(l)
        return ''.join(l)