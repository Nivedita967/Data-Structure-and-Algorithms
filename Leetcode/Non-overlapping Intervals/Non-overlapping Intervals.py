# 435. Non-overlapping Intervals
# https://leetcode.com/problems/non-overlapping-intervals/

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda interval: interval[1])
        # always pick the interval with the earliest end time.
        # becausethe interval with the earliest end time produces the maximal capacity to hold rest intervals
        ending = None
        count = 0
        for s, e in intervals:
            if ending is None or ending <= s:
                ending = e
            else:
                count += 1
        
        return count
