#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the kangaroo function below.
def kangaroo(x1, v1, x2, v2):
    if (v1 - v2)==0:
        return "NO"
    e = (x2 - x1) / (v1 - v2)                        # Calculating number of jumps to meet, if that number is an integer, then meeting is possible
    if (x2>x1) and (v2>v1):                          # Returning NO if one kangaroo is ahead of another and its speed is also more than the previous kangaroo
        return "NO"
    if (x1>x2) and (v1>v2):
        return "NO"
    if e-int(e) == 0:                                # Returning YES if number of jumps is an integer
        return "YES"
    return "NO"                                      # else returning NO
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    x1V1X2V2 = input().split()

    x1 = int(x1V1X2V2[0])

    v1 = int(x1V1X2V2[1])

    x2 = int(x1V1X2V2[2])

    v2 = int(x1V1X2V2[3])

    result = kangaroo(x1, v1, x2, v2)

    fptr.write(result + '\n')

    fptr.close()
