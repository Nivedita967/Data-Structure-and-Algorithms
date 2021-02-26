# A program in Python to find highest divisor of a given input between 1 and 10 inclusive

from sys import exit
number = int(input())                  #TODO: Get input integer
test = 10
while test > 0:
    if (number % test) == 0:           #TODO: Determine and print result
        print(test)
        exit(0)
    test -= 1
