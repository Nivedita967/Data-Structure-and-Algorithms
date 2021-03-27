# A string is said to be a child of a another string if it can be formed by deleting 0 or more characters from the other string.
#  Letters cannot be rearranged. Given two strings of equal length, 
#  what's the longest string that can be constructed such that it is a child of both?

def commonChild(s1, s2):
    m = [[0]*(len(s2)+1) for _ in range(len(s1)+1)] # Initialize the grid with 0
    # Use enumerate to track both index as well as value
    # Traverse s1 from 1st index
    for i,c in enumerate(s1,1):
          # Traverse s2 from 1st index
        for j,d in enumerate(s2,1):
            # Similar to LCS if values are equal then   m[i][j] = m[i-1][j-1]+1
            if c == d:
                m[i][j] = m[i-1][j-1]+1
            else:
                m[i][j] = max(m[i][j-1],m[i-1][j])
    # the length of the longest string which is a common child of the input strings
    return m[-1][-1]
