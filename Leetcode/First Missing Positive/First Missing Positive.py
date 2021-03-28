#Problem:https://leetcode.com/problems/first-missing-positive/
#Approach:
# Sort the list as you iterate through it by placing the elements in its index + 1 position
# Realize that the answer must be within the range of 0 to the length of the list + 1

def firstMissingPositive(self, nums: List[int]) -> int:
    i, j = 0, len(nums)

    while i < j:
        # Element is already in the right position - do nothing
        if nums[i] == i + 1:
            i += 1

        # If the number is within our range (0, j) and the number is not in its nth + 1 position then swap
        elif nums[i] > 0 and nums[i] <= j and nums[nums[i] - 1] != nums[i]:
            nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]

        # Outsite our range or a duplicate, swap to the end of list
        else:
            j -= 1
            nums[j], nums[i] = nums[i], nums[j]

    return j + 1
