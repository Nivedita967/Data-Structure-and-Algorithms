import math
import os
import random
import re
import sys
def hourglassSum(arr):
    max=-358278 #assign any smallest number to max which will help in comparison.
    for i in range(4):
        for j in range(4):
            current_sum=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j+1]+arr[i+2][j]+arr[i+2][j+2] #adding the values of positions corresponding to hourglass.
            
            #comparing sum with maximum value
            if(current_sum>max):
                max=current_sum
    return(max)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
