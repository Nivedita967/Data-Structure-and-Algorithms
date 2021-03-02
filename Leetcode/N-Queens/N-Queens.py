"""
https://leetcode.com/problems/N-Queens/

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output:
[[".Q..",
  "...Q",
  "Q...",
  "..Q."],
 ["..Q.",
  "Q...",
  "...Q",
  ".Q.."]]
  
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:
Input: n = 1
Output: [["Q"]]
"""
from typing import List

class Solution():
    def solveNQueens(self, n) -> List[List[str]]:
        
        # Represent board as matrix of characters to place Queens when needed
        board = [['.' for i in range(n)] for j in range(n)]

        result = []  # Initialize result as empty array

        # Call DFS traversing Column by Column. Starting at column 0.
        self.dfs(board, 0, result)

        # Return result
        return result

    def dfs(self, board, colIndex, result):
        # Terminating condition - to check if we reach the end of the board
        if colIndex == len(board):
            result.append(self.construct(board))
            return

        # In given column, we can put the queen in any row as long as we don't get in the way of other queens on the board
        for i in range(len(board)):
            if self.validate(board, i, colIndex):
                board[i][colIndex] = 'Q'
                self.dfs(board, colIndex + 1, result)
                board[i][colIndex] = '.'

    def validate(self, board, x, y):
        # Goes through the whole board to see if any Queen lies horizontal or diagonal for the Queen you're about to place
        for i in range(len(board)):
            for j in range(y):
                if board[i][j] == 'Q' and (x + j == y + i or x + y == i + j or x == i):
                    return False
        return True


    def construct(self, board):
        # Constructs the result as List[String]
        res = []
        s = ""  # Initailize empty string
        for i in range(len(board)):
            res.append(s.join(board[i]))  # Convert row to string
        return res


if __name__ == '__main__':
    print(Solution().solveNQueens(4))
