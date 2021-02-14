#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the isBalanced function below.
def isBalanced(s):
    # creating a stack
    stack=[]
    
    # iterating for each character in string
    for i in s:
        # if there is open bracket of any type push into stack
        if i=='{' or i=='[' or i=='(':
            stack.append(i)
            
        else:
            # using try and except if element at first index is closed bracket than position -1 is not accessible and return NO in except block
            try:
                # if last element in stack and current element is a matched pair remove the last element from stack
                if stack[-1]=='(' and i==')':
                    stack.pop()
                    
                # if last element in stack and current element is a matched pair remove the last element from stack
                elif stack[-1]=='{' and i=='}':
                    stack.pop()
                    
                # if last element in stack and current element is a matched pair remove the last element from stack
                elif stack[-1]=='[' and i==']':
                    stack.pop()
                
                # otherwise return NO for not balanced
                else:
                    return 'NO'
            except:
                return 'NO'
            
    # if stack is not empty than pairs are not matched. Hence, return NO otherwise YES
    if len(stack)!=0:
        return 'NO'
    else:
        return 'YES'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        s = input()

        result = isBalanced(s)

        fptr.write(result + '\n')

    fptr.close()
