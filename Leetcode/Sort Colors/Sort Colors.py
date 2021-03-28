class Solution:
    def sortColors(self, nums: List[int]) -> None:
        # If 2, put it at the tail
        # if 0, put it at the head and move idx to next
        # If 1, move idx to next
        
        idx = 0
        for _ in range(len(nums)):
            if nums[idx] == 2:
                nums.append(nums.pop(idx))
                continue
            elif nums[idx] == 0:
                nums.insert(0, nums.pop(idx))
            idx += 1