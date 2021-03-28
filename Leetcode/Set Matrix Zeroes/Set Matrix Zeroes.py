# Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.
# Follow up:
# A straight forward solution using O(mn) space is probably a bad idea.
# A simple improvement uses O(m + n) space, but still not the best solution.
# Could you devise a constant space solution?


# use the first row and first column to 
# record whether that row or column should
# be set to 0, the first row and column themselves
# should take care
def setZeroes(self, matrix):
    if not matrix:
        return 
    r, c = len(matrix), len(matrix[0])
    # check the first row
    zeroRow = 1
    for i in xrange(c):
        if matrix[0][i] == 0:
            zeroRow = 0
            break
    # check all the matrix
    for i in xrange(1, r):
        for j in xrange(c):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                matrix[0][j] = 0
    # set rows
    for i in xrange(1, r):
        if matrix[i][0] == 0:
            for j in xrange(c):
                matrix[i][j] = 0
    # set columns
    for j in xrange(c):
        if matrix[0][j] == 0:
            for i in xrange(1, r):
                matrix[i][j] = 0
    # set the first row
    if zeroRow == 0:
        for i in xrange(c):
            matrix[0][i] = 0