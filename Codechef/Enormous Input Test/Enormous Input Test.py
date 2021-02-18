#Reading input n,k
n,k = map(int, input().split())
count = 0    #count denotes number of integers divisible by 3

for _ in range(0, n):
    t = int(input())
    #check for divisibility by 3
    if t%k==0:
    #If t is divisible by 3 increment count by 1
        count+=1
        
#print answer
print(count)
