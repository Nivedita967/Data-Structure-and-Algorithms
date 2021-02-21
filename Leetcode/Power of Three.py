'''
A python program to implement Power of Three
Given an integer n, return true if it is a power of three. Otherwise, return false.
'''
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n == 1:
            return True
        if n < 1 or n%3 != 0:
            return False
        return self.isPowerOfThree(n/3)
    
'''
Sample Input/Output:
    
Example 1:
Input: n = 27
Output: true

Example 2:
Input: n = 0
Output: false
'''