
def subsets(nums):
    #def subsets(self, nums: List[int]) -> List[List[int]]
    result = []
    sub = []
    
    #A function to backtrack and store the subsets in the result set(power set)
    def helper(i):
        if i >= len(nums):
            #here we append a copy since a direct append would modify the entire list
            result.append(sub.copy())
            return 
        
        #to include nums[i]
        sub.append(nums[i])
        helper(i+1)
        
        #to NOT include nums[i]
        sub.pop()
        helper(i+1)
        
    helper(0)
    return result

inputs = int(input("Enter the number of unique elements: "))
input_string = input("Enter the elements seperated by space: ")
ElementList = input_string.split()

list(set(ElementList)) #This line is here, just to ensure there are no duplicates in the list

print(subsets(ElementList))
