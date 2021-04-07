#!/bin/python3

import os
import sys

#
# Complete the pageCount function below.
#
def pageCount(n, p):
    fr = 0
    en = 0
    if p%2==0:                         # Calculating number of pages turned from front
        fr = p/2
    else:
        fr = (p-1)/2
    if n%2 == 0:                       # Calculating number of pages turned from the end
        if p%2 == 0:
            en = (n-p)/2
        else:
            en = ((n-(p+1))/2)+1
    else:
        if p%2 ==1:
            en = (n-p)/2
        else:
            en = (n-(p+1))/2
            
    return int(min(fr,en))            # Returning minimum number of pages turned 
        
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    p = int(input())

    result = pageCount(n, p)

    fptr.write(str(result) + '\n')

    fptr.close()
