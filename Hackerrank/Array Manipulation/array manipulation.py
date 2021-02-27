#!/bin/python3

import math
import os
import random
import re
import sys


def arrayManipulation(n, queries):
    diffs = getArrayOfDiffs(n, queries)
    return maxFromDiffs(diffs)


def maxFromDiffs(diffs):
    sumSoFar = 0
    maxSoFar = 0
    for diff in diffs:
        sumSoFar += diff
        if sumSoFar > maxSoFar:
            maxSoFar = sumSoFar
    return maxSoFar


def getArrayOfDiffs(n, queries):
    # An array used to capture the difference of an element
    # compared to the previous element.
    # Therefore the value of diffs[n] after all array manipulations is
    # the cumulative sum of values from diffs[0] to diffs[n - 1]
    diffs = [0] * n
    for a, b, k in queries:
        # Adds "k" to all subsequent elements in the array
        diffs[a - 1] += k
        # Ignore if b is out of range
        if (b < n):
            # Subtracts "k" from all subsequent elements in the array
            diffs[b] -= k

    return diffs


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    nm = input().split()
    n = int(nm[0])
    m = int(nm[1])
    queries = []

    for _ in range(m):
        queries.append(list(map(int, input().rstrip().split())))

    result = arrayManipulation(n, queries)
    fptr.write(str(result) + '\n')
    fptr.close()
