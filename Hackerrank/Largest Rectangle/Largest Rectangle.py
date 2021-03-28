"""

Skyline Real Estate Developers is planning to demolish a number of old, unoccupied buildings and construct a shopping mall in their place. 4
Your task is to find the largest solid area in which the mall can be constructed.


"""


# For each element(height) of an array,
# 1. Search the continuous buildings to the left
#    - if continous building is at the same height or taller, increment the count
# 2. Seach the continuous buildings to the right
#    - if continous building is at the same height or taller, increment the count
# 3. Calculate the current rectangle area: 
#    - height of the current building * current count
# 4. Check if the current area is larger than the current maximum area
# When the search finishes print the maximum area acquired.
def largestRectangle(h):
    max_area = 0
    for i in range(len(h)):
        cnt = 0
        for j in range(i, -1, -1):
            if h[j] >= h[i]:
                cnt += 1
            else:
                break
        for k in range(i+1, len(h)):
            if h[k] >= h[i]:
                cnt += 1
            else:
                break
        area = h[i] * cnt
        if area > max_area:
            max_area = area

    print (max_area)

#  main func
n = int(input())
h = [int(x) for x in input().split(" ")]
largestRectangle(h)