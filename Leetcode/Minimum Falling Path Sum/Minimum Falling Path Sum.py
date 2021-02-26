"""
A python program to implement Minimum Falling Path Sum
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

"""

class Solution(object):
    def minFallingPathSum(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        def children(row, col):
            if row < rows - 1:
                yield row + 1, col
                if col > 0: yield row + 1, col - 1
                if col < cols - 1: yield row + 1, col + 1

        def search(row, col):
            if (row, col) in mem: return mem[row, col]
            mem[row, col] = A[row][col]
            childs = list(search(r, c) for r, c in children(row, col))
            if childs: mem[row, col] += min(childs)
            return mem[row, col]

        if not A: return 0
        rows, cols = len(A), len(A[0])
        mem = {}
        return min(search(0, c) for c in range(cols))
      
"""
Sample Input/Output:
Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59

"""
