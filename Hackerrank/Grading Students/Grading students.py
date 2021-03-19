#!/bin/python3

import math
import os
import random
import re
import sys

def gradingStudents(grades):
    lst=[] #Create a new list to store updated marks
    for x in grades:
        if x>=38: 
            #Checks if difference between x and the next multiple of 5 is less than 3
            y=x//5
            z=(y+1)*5 #Next multiple of 5
            if z-x<=2:
                lst.append(z) #Adds rounded mark to lst
            else:
                lst.append(x) #Adds the same mark to lst
        else:
            lst.append(x) #Adds the same mark to lst
    return lst            
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    grades_count = int(input().strip())

    grades = []

    for _ in range(grades_count):
        grades_item = int(input().strip())
        grades.append(grades_item)

    result = gradingStudents(grades)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
