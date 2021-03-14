# A program in python to find whether a box of a given dimension can pass a tunnel of height 41 


t= int(input())                             # Getting number of test cases 

for i in range(t):
    a = list(map(int, input().split()))     # Getting the array of dimensions
    if a[2] < 41:                           # Printing the volume if height of the box is less than 41
        print(a[0]*a[1]*a[2])
