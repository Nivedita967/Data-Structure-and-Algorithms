#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the hurdleRace function below.
def hurdleRace(k, height):
    height = list(height)
    height.sort(reverse = True)                   # Sorting hurdles in descending order
    doses = 0
    if height[0]>k:                               # Calculate doses needed to cross maximum height hurdle
        doses = height[0]-k
    return doses                                  # Returning required number of doses

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    height = list(map(int, input().rstrip().split()))

    result = hurdleRace(k, height)

    fptr.write(str(result) + '\n')

    fptr.close()
