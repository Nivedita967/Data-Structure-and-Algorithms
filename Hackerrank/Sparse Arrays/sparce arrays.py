#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the matchingStrings function below.
def matchingStrings(strings, queries):
    lst=[]  #Creating an empty list
    for x in queries:  #Taking elements in queries one by one
        a=0  #a=0 for every loop
        for i in range(len(strings)):  #Taking elements in strings one by one
            if strings[i]==x:  #Checking if the nth element of queries is in strings
                a=a+1  #If yes, value of a is increased
        lst.append(a)  #Adding a to the list
    return lst  #Returning the required list

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    strings_count = int(input())

    strings = []

    for _ in range(strings_count):
        strings_item = input()
        strings.append(strings_item)

    queries_count = int(input())

    queries = []

    for _ in range(queries_count):
        queries_item = input()
        queries.append(queries_item)

    res = matchingStrings(strings, queries)

    fptr.write('\n'.join(map(str, res)))
    fptr.write('\n')

    fptr.close()