# Approach:
# Main observation, The least difference between the numbers, the higer the value after modulo
# eg:
#  -1%7=6
#  -2%7=5
#  and so on so we have to minimize the difference between them. 
 # 	The main problem in the question was to find just greater number than our prefixSum. For that we used bisect, 
# 	bisect_right tell you if their is any greater element than our current element. 

# formula used is:
# 	(prefixSumSoFar-JustGreaterPrefixSum+modulo)//modulo is added because we dont want negative result.

import bisect
t=int(input())
for _ in range(t):
	n,m=map(int,input().split())
	l=list(map(int,input().split()))
	maxi=0
	prefixSum=0
	SortedPrefix=[]
	for i in range(n):
		prefixSum=(prefixSum+l[i])%m #storing prefix sum after modulo as (a%m+b%m)==(a+b)%m 
		maxi=max(maxi,prefixSum) #our maximum sum after modulo
		index=bisect.bisect_right(SortedPrefix,prefixSum) #check if there is any value greater then our current prefix value in list,
		 # this is bianry look up so it take logN time
		if index<len(SortedPrefix): #if there is any number greater then current value then index has the index of first greater value or just greater value then our current prefixSum
			maxi=max(maxi,(prefixSum-SortedPrefix[index]+m)%m)

		bisect.insort(SortedPrefix,prefixSum) #insert in the list in sorted order, this also takes O(logN) time

	print(maxi)