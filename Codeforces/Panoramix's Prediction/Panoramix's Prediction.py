# declaring global array of primes within constraints  (2 ≤ n < m ≤ 50)
prime=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,100000000];
n = int(input("Enter the value of n: "))
m = int(input("Enter the value of m: "))
flag = False # Initalially flag is false
#  Traversing each element of prime array
for i in range(0,15):
    # If the condition gets True that means: m is next prime number after n
    if(prime[i] == n and prime[i+1] == m):
        flag = True
        break
if(flag):
    print("YES")
else:
    print("NO")