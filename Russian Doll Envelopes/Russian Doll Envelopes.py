#Problem:https://leetcode.com/problems/russian-doll-envelopes/description/

import operator
import bisect
from typing import List

class Solution:
    def maxEnvelopes(self, en: List[List[int]]) -> int:
        #sort envelopes by width and reverse height 
        en.sort(key=lambda x: (x[0], -x[1])) 
        #perform binary search on just heights 
        heights = [h for _, h in en] 
        res = [] 
        for h in heights:
            idx = bisect.bisect_left(res, h)
            res[idx:idx+1] = [h] # if idx > len(res), then res will expand by 1, otherwise, we just replace existing element
        return len(res)

envelopes = [[5,4],[6,4],[6,7],[2,3]]
sol = Solution()
print(sol.maxEnvelopes(envelopes))
