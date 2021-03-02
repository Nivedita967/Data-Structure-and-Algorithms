"""
A python program to implement Counting Bits
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

"""


class Solution:
    def countBits(self, num: int) -> List[int]:
        result= [0]
        for i in range(1, num+1):
            result.append(result[i>>1] + int(i&1))
        return result
      
"""
Sample Input/Output:
Example 1:
Input: 2
Output: [0,1,1]

Example 2:
Input: 5
Output: [0,1,1,2,1,2]

"""
