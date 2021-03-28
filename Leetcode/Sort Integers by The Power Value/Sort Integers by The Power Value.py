#Problem:https://leetcode-cn.com/problems/sort-integers-by-the-power-value/description/
class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:q
        d = {}
        for i in range(10):
            d[2**i] = i
        #calculate power value of number 
        def helper(num):
            if num in d:
                return d[num]
            if num % 2:
                ans = helper(num*3+1)+1
            else:
                ans = helper(num//2)+1
            d[num] = ans
            return ans
        #list of elements between lo to hi
        nums = list(range(lo,hi+1))
        #list of all power value of elements 
        ans = [[helper(n),n] for n in nums] 
        #sort the list in ascending order of power value 
        ans.sort(key = lambda x:x[0])
        return ans[k-1][1]
