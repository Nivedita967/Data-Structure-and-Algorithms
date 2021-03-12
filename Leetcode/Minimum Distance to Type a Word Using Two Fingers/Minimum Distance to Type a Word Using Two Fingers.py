#1320. Minimum Distance to Type a Word Using Two Fingers
#https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/

INF = float('inf')
#To represent infinite integer 

class Solution:
    def dist(self, t: int, f: int) -> int:
        if f == -1:
            # -1 means finger is not placed in any letter yet
            return 0
        #manhattan distance between keyboard coordinates
        return abs(t // 6 - f // 6) + abs(t % 6 - f % 6)
        
    def minimumDistance(self, word: str) -> int:
        # dp[i,j] is minimum cost when 2 fingers are at letter i, j
        dp = {(-1,-1) : 0}        
        for c in word:
            newDp = {}
            k = ord(c) - ord('A')
            # Based on current 2 finger positions, move each finger to c.
            for i,j in dp.keys():
                #2d array to get position of word when have minimum distance 
                newDp[i,k] = min(newDp.get((i,k), INF), dp[i,j] + self.dist(k,j))
                newDp[k,j] = min(newDp.get((k,j), INF), dp[i,j] + self.dist(k,i))
             #store value of minimum distance in dictionary 
            dp = newDp
        #Required minimum Distance 
        return min(dp.values())
