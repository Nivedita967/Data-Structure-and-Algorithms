
# Python program for recursive digit sum
import math
import os
import random
import re
import sys

# Complete the superDigit function below.
def superDigit(n, k):
    #return answer
    return 1 + (k * sum(int(x) for x in n) - 1) % 9


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
     ## taking input
    nk = input().split()

    n = nk[0]

    k = int(nk[1])

    result = superDigit(n, k)

    fptr.write(str(result) + '\n')

    fptr.close()

