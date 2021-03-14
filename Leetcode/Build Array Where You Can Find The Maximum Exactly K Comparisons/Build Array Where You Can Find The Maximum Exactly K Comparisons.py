# Recursive Relation:
# dp(n, i, j) = dp(n-1, i, j)*(i+1)+
#    	  sum([dp(n-1,x,j+1) for x in range(i)])
class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
    	mod=1000000007

    	if k==0: #optimal case
    		return 0

    	dp=[]
    	for _ in range(m):
    		dp.append([0]*k-1+[1]) #creating a matrix

    	for _ in range(n-1):
    		new_dp=[]
    		for _ in range(m):
    			new_dp.append([0]*k) #creating another empty matrix

    		for i in range(m):
    			for j in range(k):

    				#adding a smaller value than i
    				new_dp[i][j] += dp[i][j]*(i+1)

    				#adding i which is larger than before
    				if j<k-1:

    					for x in range(i):
    						new_dp[i][j]+=dp[x][j+1]

    				#take mod
    				new_dp[i][j] = new_dp[i][j]%mod

    		dp=new_dp

    	ans=sum(a[0] for a in dp)
    	for a in dp:
    		ans+=a[0]
    	return ans%mod