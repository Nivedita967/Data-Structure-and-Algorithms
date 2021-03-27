# Complete the longestCommonSubsequence function below.
def longestCommonSubsequence(a, b):
    m, n = len(a), len(b)   #use len() to get length of list a and b
    dp = [ [ [] for j in range(n+1)] for i in range(m+1) ]  #creating an empty array 
    for i in range(1, m+1):
        for j in range(1, n+1):
            if a[i-1] == b[j-1]:  #check the condition
                dp[i-1][j-1].append(a[i-1])
                dp[i][j] = dp[i-1][j-1].copy()
            else:
                temp = max( dp[i][j-1], dp[i-1][j], key= len)
                dp[i][j] = temp.copy()
    return dp[m][n]
  
'''
Sample Input
5 6
1 2 3 4 1
3 4 1 2 1 3

Sample Output

1 2 3
'''
