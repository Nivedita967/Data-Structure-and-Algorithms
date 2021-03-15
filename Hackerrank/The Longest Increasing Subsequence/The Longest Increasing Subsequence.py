#Problem:https://www.hackerrank.com/challenges/longest-increasing-subsequent/problem

def lengthOfLIS(self, nums):
    #array of length 0 to nums – 1, and fill this with 0
    tails = [0] * len(nums)
    size = 0
    for x in nums:
        i, j = 0, size
        while i != j:
            mid = (i + j) / 2
            if tails[mid] < x:
                i = mid + 1
            else:
                j = mid
        tails[i] = x
        size = max(i + 1, size)
    return size

ob1 = Solution()
lst = [] 
# number of elemets as input 
n = int(input("Enter number of elements : "))  
# iterating till the range 
for i in range(0, n): 
    ele = int(input()) 
    lst.append(ele)
print(ob1.lengthOfLIS(lst))
