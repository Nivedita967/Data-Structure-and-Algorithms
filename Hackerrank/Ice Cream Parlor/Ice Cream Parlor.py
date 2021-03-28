"""
Two friends like to pool their money and go to the ice cream parlor. They always choose two distinct flavors and they spend all of their money.
Given a list of prices for the flavors of ice cream, select the two that will cost all of the money they have.
"""

def icecreamParlor(m, arr):
    # Create an empty dictionary
    s={}
    for i in range (len(arr)):
        # m-arr[i] would complement arr[i] to make sum of money m
        if m-arr[i] in s:
            # required Flavors infex ( 1 based index)
            return [s[m-arr[i]],i+1]
        else:
            # else: add it to dictionary s: (here 1 is added becz it is 1 based indexing )
            s[arr[i]]=i+1