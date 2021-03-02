 # A program to find sum of maximum elements such that, no two elements are same

# Given array
arr = [5, 5, 10, 100, 10, 5] 

sumOdd = 0
sumEven = 0

# Calculating the sum of odd and even indexed elements separately
for i in arr:
    if sumEven>sumOdd:
        ele = sumEven  
    else: 
        ele = sumOdd 
    sumOdd = sumEven + i 
    sumEven = ele 

# Printing the maximum sum calculated
if sumEven>sumOdd:
    print(sumEven)
else:
    print(sumOdd)
