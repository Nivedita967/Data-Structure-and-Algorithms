import math
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1.extend(nums2) #appending second list into the first
        nums1.sort() #sorting the new merged list
        if(len(nums1)%2==0): #if length of list is even then mid and mid+1 is median, but since it's a 0 based indexing here avg of mid-1 and mid is median
            mid=int(len(nums1)/2)
            return (nums1[mid]+nums1[mid-1])/2
        else:
            mid=math.ceil(len(nums1)/2) #if the number is odd mid number is median
            return nums1[mid-1]