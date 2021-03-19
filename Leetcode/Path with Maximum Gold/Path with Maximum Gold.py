"""
Problem Statement:
In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position you can walk one step to the left, right, up or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.


Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.


Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.

"""

class Solution(object):
    def getMaximumGold(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # nRow will be storing the number of rows in the grid & nCol is the number of columns in the grid
        nRow, nCol = len(grid), len(grid[0])
        res = 0
        # Traverse each elemet of the grid
        for r in range(nRow):
            for c in range(nCol): 
                if grid[r][c] == 0: continue # if the element is not 0 then only perform DFS
                stack = [(r, c, {(r, c)}, grid[r][c])] # Create a stack of currentRow r, currentColumn c, {(r,c)} is the corordinate & grid[r][c] is the value of elemet
                while stack:
                    x, y, path, d = stack.pop() # pop elements and put it in respective variables
                    res = max(res, d) 
                    # [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)] == [(previous row, currentCol),(nextRow,currentCol),(currentRow,previous Column), (currentRow, nextCol)]
                    for x1, y1 in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]:
                        if 0 <= x1 < nRow and 0 <= y1 < nCol and (x1, y1) not in path and grid[x1][y1] != 0:
                            stack += [(x1, y1, path | {(x1, y1)}, d + grid[x1][y1])]
        return res