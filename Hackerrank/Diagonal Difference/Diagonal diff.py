#!/bin/python3

import math
import os
import random
import re
import sys

#Required function
def diagonalDifference(arr):
    d1 = sum([arr[x][x] for x in range(len(arr))]) #Calculate the sum of diagonal 1
    d2 = sum([arr[x][n - 1 - x] for x in range(len(arr))]) #Calculate the sum of diagonal 2
    return(abs(d1 - d2)) #Returns the absolute difference of the sums calculated above

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
