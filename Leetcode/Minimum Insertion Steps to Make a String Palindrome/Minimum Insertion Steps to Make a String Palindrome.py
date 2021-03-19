class Solution:
    def minInsertions(self, s: str) -> int:
    
        m=len(s)          # Calculating the length of the string
        
        t=[[0 for i in range(m+1)] for i in range(m+1)]
        r=s[::-1]         # Reversing the string
        for i in range(1,m+1):
            for j in range(1,m+1):           # Evaluating result by iterating through every character twice
                if m==0:
                    t[i][j]=0
                elif s[i-1]==r[j-1]:
                    t[i][j]=t[i-1][j-1]+1
                else:
                    t[i][j]=max(t[i-1][j],t[i][j-1])
        return m-t[m][m]  # Returning result
