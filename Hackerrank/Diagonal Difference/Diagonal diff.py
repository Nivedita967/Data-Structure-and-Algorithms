#!/bin/python3

import math
import os
import random
import re
import sys

def diagonalDifference(arr):
    d1 = sum([arr[x][x] for x in range(len(arr))])
    d2 = sum([arr[x][n - 1 - x] for x in range(len(arr))])
    return(abs(d1 - d2))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
