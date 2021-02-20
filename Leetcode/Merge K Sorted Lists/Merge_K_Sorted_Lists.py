# Title: Merge k Sorted Lists
# Link: https://leetcode.com/problems/merge-k-sorted-lists/

from typing import List


class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

"""
    Loop while we lists is not empty.
    Check which node of the linked lists is least and set it as 
    the next node and set that node equal to it's next. 
    if a list is empty remove it from lists.

    For every Linked List in lists. Loop through nodes till you reach the end,
    appending each node to nodes. Sort nodes. Add every node in nodes together and return    
    head.next
"""

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists:
            return None

        nums = []
        for l in lists:
            while l:
                nums.append(l.val)
                l = l.next

        head = current = ListNode(0)
        for n in sorted(nums):
            current.next = ListNode(n)
            current = current.next

        return head.next
