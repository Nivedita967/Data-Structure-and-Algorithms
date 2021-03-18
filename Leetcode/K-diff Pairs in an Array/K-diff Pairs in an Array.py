
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        
            # If the diff has to be 0, find how many numbers occur more than 1 time
            # If 5 occurs twice, that means 5-5 = 0, and thats 1 diff pair
        if k == 0:
            freq = Counter(nums)
            return sum([v > 1 for k,v in freq.items()])
        
        
        # Set because we don't want duplicate computations
        nums = list(set(nums))
    
        # Sort the set list because we start from the beginning and need to calc diffs
        nums.sort()
        
        i = 0
        j = 0
        count = 0
       
        while j < len(nums):
            diff = abs(nums[i] - nums[j])
        
            # If the diff is exactly k, move both i and j up AND increment count
            if diff == k:
                count+=1
                i+=1
                j+=1

           # If the diff is lower than k, that means that the difference needs to increase,

            elif diff < k:
                j+=1

# Since both i and j are high, we know that the difference between two big numbers is small
            elif diff > k:
                i+=1
        
        
        return count
        
