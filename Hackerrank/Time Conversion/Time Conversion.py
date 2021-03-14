# A program in python to convert 12 hour clock time to 24 hour clock time

import os
import sys


# You have only to complete the timeConversion function below, rest of the code will be given by hackerrank itself.

def timeConversion(s):
    if s[-2]=='P':                                   # Checking the given time is am or pm and calculating required time by slicing the given string
        if s[0:2]=='12':
            s=s[0:8]
        else:
            s=str(int(s[0:2])+12)+s[2:8]
    else:
        if s[0:2]=='12':
            s='00'+ s[2:8]
        else:
            s=s[0:8]
    return s

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()                                      # Getting input

    result = timeConversion(s)                       # Calculating time in 24 hr clock

    f.write(result + '\n')                           # Printing result

    f.close()
