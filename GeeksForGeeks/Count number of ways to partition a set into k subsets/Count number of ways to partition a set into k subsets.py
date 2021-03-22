"""
Given two numbers n and k where n represents a number of elements in a set, find a number of ways to partition the set into k subsets.

Input: n = 3, k = 2
Output: 3

Input: n = 3, k = 1
Output: 1


Approach:
1. The previous n – 1 elements are divided into k partitions, i.e S(n-1, k) ways. Put this nth element into one of the previous k partitions.
 So, count = k * S(n-1, k)
2. The previous n – 1 elements are divided into k – 1 partitions, i.e S(n-1, k-1) ways. Put the nth element into a new partition 
 ( single element partition).So, count = S(n-1, k-1)
3. Total count = k * S(n-1, k) + S(n-1, k-1).
"""

# countP is a recursive function that returns the number of ways to partition a set into k subset
def countP(n, k):
	
	# Base cases
    # there can not be any subset so return 0
	if (n == 0 or k == 0 or k > n):
		return 0
    # There can only be a subset so return 1
	if (k == 1 or k == n):
		return 1
	
	# S(n+1, k) = k*S(n, k) + S(n, k-1)
    
        # 1. If the previous n – 1 elements are divided into k partitions, i.e S(n-1, k) ways. Put this nth element into one of the previous k partitions.
        #     So, count = k * S(n-1, k)
        # 2. If the previous n – 1 elements are divided into k – 1 partitions, i.e S(n-1, k-1) ways. Put the nth element into a new partition 
        #     ( single element partition).So, count = S(n-1, k-1)
        # 3. Total count = k * S(n-1, k) + S(n-1, k-1).
	return (k * countP(n - 1, k) + countP(n - 1, k - 1))

# Driver Code
if __name__ == "__main__":
    n = int(input("Enter the value of n: "))
    k = int(input("Enter the value of k: "))
    print(countP(n,k))

