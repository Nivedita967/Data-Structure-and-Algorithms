"""
Problem Statement:

You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.


Input: grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
Output: [0,1,2,3,4,-1]

"""
"""
Solution:
The ball can only fall in one of two ways:
Fall from (row,col) to (row+1,col+1) if grid[row][col]==1 and grid[row][col+1] == 1
Fall from (row,col) to (row+1,col-1) if grid[row][col]==-1 and grid[row][col-1] == -1
"""

class Solution(object):
    def findBall(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        numberOfColumns = len(grid[0]) # Number of columns in the grid.
        fallLocations = []  # The answer List
        for startingColumn in range(numberOfColumns):  # Traversing each colummn one by one
            fallLocations.append(self.findBallFallLocation(grid, startingColumn))
        return fallLocations
    
    def findBallFallLocation(self, grid, startingColumn):
        numberOfRows = len(grid)  # number of rows in the grid
        numberOfColumns = len(grid[0]) # Number of columns in the grid
        ballColumnLocation = startingColumn # Initiallly the ball will be at its respective starting column
        for ballRowLocation in range(numberOfRows):
            # if the value of grid at which the ball is currently is 1 (left to right) then check if the value at same row but next column element is 1 (left to right) or not.
            # If it is 1 that means the ball will move right hence increment he ballColumnLocation by 1.
            if grid[ballRowLocation][ballColumnLocation] == 1 and ballColumnLocation + 1 < numberOfColumns and grid[ballRowLocation][ballColumnLocation + 1] == 1:
                ballColumnLocation = ballColumnLocation + 1
                continue
             # if the value of grid at which the ball is currently is -1 (right to left) then check if the value at same row but previous column element is -1 (right to left) or not.
             # If it is -1 that means the ball will move left hence decrement he ballColumnLocation by 1.
            if grid[ballRowLocation][ballColumnLocation] == -1 and ballColumnLocation - 1 >= 0 and grid[ballRowLocation][ballColumnLocation - 1] == -1:
                ballColumnLocation = ballColumnLocation - 1
                continue
            # Else the ball has got stuck hence return -1
            return -1
        return ballColumnLocation