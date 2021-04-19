def fac(n):                   # Recursive function for factorial
    if n == 0:
        return 1
    return n*fac(n-1)
    
    
n = int(input())              # Getting user input
r = fac(n)
print(r)                      # Printing result
