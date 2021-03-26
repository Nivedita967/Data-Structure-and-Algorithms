

# Python program to print all permutations with
# duplicates allowed
def toString(List):
    return ''.join(List)
  
# Function to print permutations of string
# This function takes three parameters:
# 1. String
# 2. Starting index of the string
# 3. Ending index of the string.
def permutation(a, l, r):
    if l == r:
        print(toString(a))
    else:
        for i in range(l, r + 1):
            a[l], a[i] = a[i], a[l]
            permutation(a, l + 1, r)
            a[l], a[i] = a[i], a[l] # backtrack
  
# Driver program to test the above function
string = input("Enter the string: ")
n = len(string)
arr = list(string)
permutation(arr, 0, n-1)

