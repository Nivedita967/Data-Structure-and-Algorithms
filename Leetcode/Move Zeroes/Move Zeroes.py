class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        
        non_zeros = [i for i in range(len(nums)) if nums[i] != 0] # List comprehension to keep only numbers that are non -zero
        nz = len(non_zeros) 
        nums[:nz] = [nums[i] for i in non_zeros]     # edit the list to add non zero numbers to the list   
        nums[nz:] = [0] *(len(nums)-nz) #dd zeroes at the end