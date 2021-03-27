import sys

#Function to find left element
def find_left(arr):
    lstack = [1]
    #Create an empty list to add lefts of each element in the future
    output = []
    
    for ind in range(1, len(arr)-1):
        while lstack and arr[lstack[-1]-1] <= arr[ind]:
            lstack.pop()
        
        left = lstack[-1] if lstack else 0
        lstack.append(ind+1)
        #Append lefts of each element to a list
        output.append(left)
    #Returns the list of lefts
    return output

#Function to find right element
def find_right(arr):
    arr_len = len(arr)
    rstack = [1]
    #Create an empty list to add lefts of each element in the future
    output = []
    
    for ind in range(1, len(arr)-1):
        while rstack and arr[rstack[-1]-1] <= arr[ind]:
            rstack.pop()
        
        right = arr_len - rstack[-1] + 1 if rstack else 0
        rstack.append(ind+1)
        #Append lefts of each element to a list
        output.append(right)
    #Returns the list of rights in reverse order
    return output[::-1]
    
#Function to find the maximum of products of left and right
def solution(arr):
    res = 0
    
    left = find_left(arr)
    right = find_right(arr[::-1])
    #For loop to find the maximum of products
    for el in zip(left, right):
        res = max(res, el[0]*el[1])
        
    return res

if __name__ == "__main__":
    n = int(input().strip())
    arr = [int(x) for x in input().strip().split()]
    
    print(solution(arr))
