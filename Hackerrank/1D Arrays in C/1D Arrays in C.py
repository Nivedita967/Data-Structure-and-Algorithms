# Getting number of strings to be provided
t=int(input())

# Reading input as an array
lis = list(map(int,input().split()))

# Calculating sum of the list
s = 0
for i in range(t):
    s += lis[i]

# Printing the result
print(s)

    

