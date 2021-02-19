n = 10**6

# calculating prime numbers till 10**6 using sieve method
prime=[1 for i in range(n+1)]
i=2
prime[0]=0
prime[1]=0
while i*i<=n:
    if prime[i] == 1:
        for j in range(i*i,n+1,i):
            prime[j]=0
    i+=1

# calculating good tuple for each value of n beforehand
tuples=[0 for i in range(n+1)]
for i in range(2,n+1):
    # if current element and current -2 th element are prime than it's a good tuple increment
    if prime[i]==1 and prime[i-2]==1:
        tuples[i]=tuples[i-1]+1
    else:
        tuples[i]=tuples[i-1]

for _ in range(int(input())):
    # reading values of n
    n=int(input())
    
    # assigning count using tuples array
    count=tuples[n]
    print(count)
