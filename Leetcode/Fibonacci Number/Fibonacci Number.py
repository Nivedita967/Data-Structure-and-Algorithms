"""
A python program to implement Fibonacci Number
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.

"""

def fib(n):
    if n == 0 or n == 1:
        return n
    
    a = 0
    b = 1
    for i in xrange(n-1):
        c = a + b
        a = b
        b = c
     
    return b

class Solution(object):
    def fib(self , N):
        return fib(N)
        
"""
Sample Input/Output:
Example 1:
Input: n = 2
Output: 1

Example 2:
Input: n = 3
Output: 2

"""
