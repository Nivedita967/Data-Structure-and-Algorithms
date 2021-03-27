#python program to remove nth node from end of list

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        temp = head
        l = 1
        while temp.next!=None:
            # moving to next node
            temp = temp.next
            l+= 1
        c = l - n
        temp = head
        keo = head
        # if c is 0 then head moves to temp of next
        if c==0:
            head=temp.next
        while c!=0:
            # if c is not 0
            keo = temp
            temp = temp.next
            c-=1
        keo.next = temp.next
        # return head
        return head

