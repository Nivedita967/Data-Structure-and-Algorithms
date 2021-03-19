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
        l = [] #Create An Empty List
        i=0     # Initialize the counter to 0
        while (i< len(s)):
            if s[i] != "]": # On traversing each element of String if the character is not equal to ] then append the charcater to the list.
                l.append(s[i])
            else:          # If the character is == ] then pop the characters from the list until we encounter [
                t=""        # Initialize an empty String
                while (l[-1]!="["):  # Condition: pop & append to t until we reach the [
                    t =l.pop(-1)+t
                l.pop(-1) # poppping "[" (Since we are alrady on [ char)
                
                # For repeating the characters (ex: 3[a] would become aaa & 3[ab] would become ababab)
                n=""  
                while (l and l[-1].isnumeric()): # pop the list until we have digits left & add it to n
                    n= l.pop(-1)+n
                
                t= t*int(n)  # int(n) will convert the string to numeric digits ex: '30' to 30. & repeat the set of characters formed as t.
                l.append(t)  #append t to the list
            i+=1
            
        # print(l)
        return ''.join(l)