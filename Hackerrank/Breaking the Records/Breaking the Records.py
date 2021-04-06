#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the breakingRecords function below.
def breakingRecords(scores):
    scores = list(scores)                       # Getting list of scores
    mi = scores[0]
    ma = scores[0]
    mic = 0
    mac = 0
    for i in scores:                           # Counting places where the records are breaking
        if i < mi:
            mi = i
            mic += 1
        if i > ma:
            ma = i
            mac += 1
    return (str(mac),str(mic))                 # Returning results

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    scores = list(map(int, input().rstrip().split()))   # Getting input as a list

    result = breakingRecords(scores)                    # Calculating result

    fptr.write(' '.join(map(str, result)))              # Printing result
    fptr.write('\n')

    fptr.close()
