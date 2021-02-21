import numpy #NumPy a library useful in multi-dimensional arrays and matrices, and its operations
class Solution:
    def mySqrt(self, x: int) -> int:
        m=int(numpy.sqrt(x))  #square root func in NumPy which takes single argument..
        return m
    
''' 
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
'''