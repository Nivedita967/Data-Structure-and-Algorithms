# Problem Link : https://leetcode.com/problems/count-square-submatrices-with-all-ones/

# The intuition is to create a m*n array , namely 'dp' and at each cell, store the maximum area of the square
# with all 1 that could be formed and end at that cell, i.e. this cell is the bottom-right corner of the square.

# Starting from top-left corner of the dp, we store the number of such squares that can be formed.

# After each iteration we add the squares formed at that cell to variable 'ans' and return ans.

def count_squares(matrix):

    # dp to store the maximum no. of squares possible at that place
    dp = [[0 for i in range(len(matrix[0]))] for j in range(len(matrix))]

    # ans stores the total no. of squares formed.
    ans = 0

    # Looping through each cell of the given matrix.
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):

            # Corner cases as only square of dimensions [1*1] can be formed at 0th row and 0th column.
            if i == 0 or j == 0:
                dp[i][j] = matrix[i][j]

            else:
                if matrix[i][j] == 0:
                    dp[i][j] = 0
                else:

                    # Taking minimum of the left surrounding and adding one (for [1*1] square formed).
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1

            # updating our answer.
            ans += dp[i][j]
    return ans

# Example :

matrix = [
    [0, 1, 1, 1],
    [1, 1, 1, 1],
    [0, 1, 1, 1]
]
print(count_squares(matrix))
