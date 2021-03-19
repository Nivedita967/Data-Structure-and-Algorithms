# Getting number of strings to be provided
t=int(input())

lis = list(map(int,input().split()))

# Reversing the list
lis.reverse()

# Printing list
for i in range(t):
    print(lis[i],end=" ")
    
print()
