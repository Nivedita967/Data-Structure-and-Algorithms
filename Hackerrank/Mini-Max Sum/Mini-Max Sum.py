# A program in python to find minimum and maximum sum of 4 elements of a given array

import math
import os
import random
import re
import sys


def miniMaxSum(arr):
    print(sum(arr)-max(arr),sum(arr)-min(arr))                # Calculating and Printing result

if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))            # Getting user input

    miniMaxSum(arr)                                           # Calling function to find minimax sum
