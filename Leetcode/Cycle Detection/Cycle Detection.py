"""
A linked list is said to contain a cycle if any node is visited more than once while traversing the list. Given a pointer to the head of a l
inked list, determine if it contains a cycle. If it does, return 1 Otherwise, return 0


There are  scenarios to consider:
1.The list is empty (i.e.,  head is null).
2.The list does not contain a cycle, so you can traverse the list and terminate once there are no more nodes (i.e., next  is null).
3. The list contains a cycle, so you will be stuck looping forever if you attempt to traverse it.

"""

def has_cycle(head):
    fast = head;
    #  The fast pointer moves 2 nodes at a time while slow pointer moves 1 pointer at a time
    while(fast != None and fast.next != None):
        fast = fast.next.next;
        head = head.next;
        
        # Linked list has cycle
        if(head == fast):
            return True;
        #Linked list does not have any cycle
    return False;