#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c):
    
    # initializing variables
    i=0
    count=0
    
    while i<len(c)-1:
        # using try except as index can be out of bounds at index = n-2, where n is length of array
        try:
            # if jumping two blocks increment pointer by 2
            if c[i+2]==0:
                i+=2
            # if jumping one block increment pointer by 1
            else:
                i+=1
        except:
            i+=1     
        
        # incrementing the jump count
        count+=1

    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c)

    fptr.write(str(result) + '\n')

    fptr.close()
