#to calculate hourglass in python
def solve(matrix):
    hourglasses = []
    for index, line1 in enumerate(matrix):

        if index + 2 == len(matrix):
            break

        line2 = matrix[index + 1]
        line3 = matrix[index + 2]

        pattern1 = []
        pattern2 = []

        for j, val in enumerate(line1):
            val2 = line2[j]
            val3 = line3[j]

            pattern1.append(val + val3)
            pattern2.append(val + val2 + val3)
            if len(pattern1) >= 3:
                hourglasses.append(pattern1[-1] + pattern2[-2] + pattern1[-3])

    return max(hourglasses)


print(solve(parsedInput))