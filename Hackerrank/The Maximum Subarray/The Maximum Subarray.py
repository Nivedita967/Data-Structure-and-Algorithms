import sys #to use the minimum value
t=int(input()) #number of test case
for _ in range(t):
	n=int(input()) #size of list
	l=list(map(int,input().split())) #list input
	maxSofar=-sys.maxsize-1 #intializing maxSofar with smallest possible value
	CurrentMax=0
	#Kadane’s Algorithm
	for i in range(n):
		CurrentMax+=l[i];
		if(maxSofar<CurrentMax): #check if the max number we get so far is smaller than current number or not
			maxSofar=CurrentMax

		if(CurrentMax<0):
			CurrentMax=0

#For largest subarray sum

	l.sort(reverse=True) #sort the list in decreasing order
	maxSubsequence=0
	for i in range(n):
		if(l[0]==0): #if max number in list is 0
			maxSubsequence=0
			break
		if(l[0]<0): #if there is no positive element in list
			maxSubsequence=l[0]
			break
		if(l[i]>0): #if list has mixture of both add only positive number
			maxSubsequence+=l[i]

	#Output the result in desired format
	print(maxSofar,end=" ") 
	print(maxSubsequence)

