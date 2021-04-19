#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the findDigits function below.
def findDigits(n):
    count = 0
    lis = list(str(n))                  # Splitting every digit into a list of strings
    for c in lis:
        c = int(c)
        if c == 0:
            continue
        if n%c == 0:                   # Updating counter if the digit is a divisor
            count+=1
    return count                       # Returning result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())                   # Getting number of test cases

    for t_itr in range(t):
        n = int(input())              # Getting the digit(s)

        result = findDigits(n)        # Getting result

        fptr.write(str(result) + '\n')

    fptr.close()
