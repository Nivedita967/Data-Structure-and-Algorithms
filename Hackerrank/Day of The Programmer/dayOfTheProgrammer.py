#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the dayOfProgrammer function below.
def dayOfProgrammer(year):
    if (leapyear(year) and year>1918) or (year%4==0 and year<1918):
        return '12.09.'+str(year)
    else:
        if year==1918:
            return '26.09.'+str(year)
        else:
            return '13.09.'+str(year)
        
def leapyear(year):
    if year%4==0:
        if year%100==0:
            if year%400==0:
                return True
            else:
                return False
        else:
            return True
    else:
        False


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    year = int(input().strip())

    result = dayOfProgrammer(year)

    fptr.write(result + '\n')

    fptr.close()
