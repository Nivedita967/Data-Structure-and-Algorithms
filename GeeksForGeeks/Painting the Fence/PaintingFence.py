# Python3 program for Painting Fence Algorithm using dynamic programming
 
# Returns count of ways to color k posts 
def noofCounts(n, k):
     
    dp = [0] * (n + 1)
    total = k 
    mod = 1000000007 #for modulo
     
    dp[1] = k
    dp[2] = k * k    
     
    #loop on complete array 
    for i in range(3,n+1):
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod
         
    return dp[n]
   
# Driver code 
n = input('Enter number of posts')
k = input('Enter number of colours')
print(noofCounts(n, k))

