#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countApplesAndOranges function below.
def countApplesAndOranges(s, t, a, b, apples, oranges):
    for i in range(len(apples)):                          # Calculating position where the apple falls
        apples[i]+=a
    for j in range(len(oranges)):                         # Calculating position where the orange falls
        oranges[j]+=b
    counta = 0
    counto = 0
    for k in apples:                                     # Checking if the apple falls in given range
        if k>=s and k<=t:
            counta+=1
    for l in oranges:                                     # Checking if the orange falls in given range
        if l>=s and l <=t:
            counto+=1
    print(counta)
    print(counto)
            
    

if __name__ == '__main__':
    st = input().split()

    s = int(st[0])

    t = int(st[1])

    ab = input().split()

    a = int(ab[0])

    b = int(ab[1])

    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    apples = list(map(int, input().rstrip().split()))

    oranges = list(map(int, input().rstrip().split()))

    countApplesAndOranges(s, t, a, b, apples, oranges)
