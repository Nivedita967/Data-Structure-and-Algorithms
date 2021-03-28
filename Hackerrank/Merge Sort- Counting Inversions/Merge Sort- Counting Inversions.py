import math
import os
import random
import re
import sys

# Complete the countInversions function below.
def countInversions(array):
    cnt_inv = 0

    if len(array) <= 1:
        return array, 0
    # break an array in two halfs
    ar_left, inv_left = countInversions(array[:int(len(array)/2)])   # first half of the array
    ar_right, inv_right = countInversions(array[int(len(array)/2):])  # second half of the array

    ar_merged = []
    i = j = 0
    len_left = len(ar_left)  # length of the left half
    len_right = len(ar_right)  # length of the second half
    
    for k in range(len(array) - 1):
        if i == len_left or j == len_right:  # break the iteration when length of left half become equal to i or right half become equal to j
            break

        if ar_left[i] <= ar_right[j]:
            ar_merged.append(ar_left[i])
            i += 1
        else:
            ar_merged.append(ar_right[j])
            j += 1
            cnt_inv += len_left - i

    ar_merged += ar_left[i:]
    ar_merged += ar_right[j:]
    return ar_merged, cnt_inv + inv_left + inv_right
  
 if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        arr = list(map(int, input().rstrip().split()))

        arr_sorted,result = countInversions(arr)

        fptr.write(str(result) + '\n')

    fptr.close()
    
'''
Sample Input

STDIN       Function
-----       --------
2           d = 2
5           arr[] size n = 5 for the first dataset
1 1 1 2 2   arr = [1, 1, 1, 2, 2]
5           arr[] size n = 5 for the second dataset     
2 1 3 1 2   arr = [2, 1, 3, 1, 2]
-----------------------------------
Sample Output
0  
4   
'''
