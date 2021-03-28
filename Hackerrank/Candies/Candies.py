"""
Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  
All the children sit in a line and each of them has a rating score according to his or her performance in the class. 
 Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get 
 more candies. Alice wants to minimize the total number of candies she must buy.

"""


def candies(n, arr):
    # First distribute 1 candies to every child.
    candies = [1] * len(arr)
    # left -> right
    for i in range(len(arr)-1):
        # Taking in account the right of the current child having greater rating
        if arr[i] < arr[i+1]:
            candies[i+1] = max(candies[i+1], candies[i] + 1)
    # right -> left
    # Traversing in the reverse order to take into account the left of the current child having greater ranking
    for i in reversed(range(1, len(arr))):
        if arr[i] < arr[i-1]:
            candies[i-1] = max(candies[i-1], candies[i] + 1)
    # Return total number of candies required.
    return sum(candies)