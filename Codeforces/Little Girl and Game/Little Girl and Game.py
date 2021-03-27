# Approach:
# 	 Main key here is to understand the concept of plaindrome, Since the string
# 	 is palindrome it mean, it have all the number in pairs/even, i.e left half is equal
# 	 to that of right. With only one number odd, or no number odd.

# 	So say there are two odd occurances of a character than the person can only remove one
# 	character with odd occurance. This implies in each turn only one character with odd occurance
# 	will be removed. So now its upto those odd occurance characters.

# 	Say there is one character with odd occurance.i.e string is already palindrome therefore First win.
# 	if(odd_occurance==1):
# 		"First"
# 	if two character with odd occurance than 1st player will remove the first character with odd occurance, this implies
# 	Second player wins and so on.

# 	Hence=> even character with odd_occurance Second player wins
# 	else first player wins

n=input()
d={}
for i in range(len(n)): #creating a dictionary and counting occurance of each character
	if n[i] in d:
		d[n[i]]+=1
	else:
		d[n[i]]=1

even,odd=0,0
for i in d:  #counting total number of character with odd occurance
	if(d[i]%2!=0):
		odd+=1

if(odd==0): #if there is no charcter with odd occurance First player wins
	print("First") 

else:

	if(odd%2==0):  #if there are even number of character with odd occurance than second player always wins
		print("Second")
	else:
		print("First")
