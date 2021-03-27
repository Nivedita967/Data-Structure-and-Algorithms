# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Approach:- Here main key is to swap the node by adress rather than by data,

# so we create to node final and temp and made them point to start of list node

# and since we have to change every alternate node, we need to store the current , next and next of next node

# so that we dont loose track of the ListNode
# temp->1 ->2 ->3 ->4= temp->2 -> 1 -> 4 ->3

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        ans =temp= ListNode(0) #initializing the node with same type
        temp.next = head
		
        while temp.next and temp.next.next: #checking if there are sufficient node to change
            currentNode = temp.next 
            nextNode = currentNode.next

            temp.next,nextNode.next,currentNode.next=nextNode,currentNode,nextNode.next #changing all three of the node in the same place without using variable,
            #so we don't have to worry about which node comes first and which to change
            temp=currentNode

        return ans.next
