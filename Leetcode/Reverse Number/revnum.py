"""
A Python program to reverse a number.
If a number is given this program returns the reverse of that number.

"""

class Solution:
    def reverse(self, x: int) -> int:        
        result = 0
        
        is_negative = False
        if x < 0:
            is_negative = True
            x = -x
        
        while x > 0:            
            result = result * 10 + x % 10
            x = x // 10
        
        if result > 2**31 - 1 or result < -2**31:
            return 0
        
        if is_negative:
            result = -result
        
        return result

"""
Sample Case : 
Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

"""
