#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'getTotalX' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#

def getTotalX(a, b):
    a.sort()                                            # Sorting Both the given arrays
    b.sort()
    c = list(range(a[-1],b[0]+1))                       # Creating a list C of all integers between the elements of both the arrays
    
    
    rem = []
    for i in a:                                         # Removing elements from C which are not divisible by elements of list a
        for j in c:
            if j%i != 0:
                rem.append(j)
    rem = set(rem)
    for m in rem:                                       
        c.remove(m)
        
        
    rem = []
    for k in b:                                         # Removing elements from C which are not a factor of elements of list b
        for l in c:
            if k%l != 0:
                rem.append(l)
    rem = set(rem)
    for n in rem:                             
        c.remove(n)
    le = len(c)
    return le                                           # Returning length of C which has elements which satisfy the given conditions  

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    brr = list(map(int, input().rstrip().split()))

    total = getTotalX(arr, brr)

    fptr.write(str(total) + '\n')

    fptr.close()
