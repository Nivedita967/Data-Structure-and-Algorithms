from math import log

for _ in range(int(input())):
    c = int(input())
    b = 2**int(log(c, 2)) - 1
    a = c ^ b   # performing XOR operation
    print(a*b)
    
'''
Example Input
2
13
10
--------------
Example Output
70
91
'''
