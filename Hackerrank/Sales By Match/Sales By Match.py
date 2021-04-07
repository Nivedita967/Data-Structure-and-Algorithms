#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    d = {}                              # Creating a dictionary
    for i in ar:
        if i not in d:
            d[i]=0
        d[i]+=1                         # Counting number of differnt socks
    count = 0
    for j in d:
        count+= (d[j]//2)              # Counting pairs by integer division of the number of socks by 2
    return count
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())                    # Getting user input

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')     # Printing result

    fptr.close()
