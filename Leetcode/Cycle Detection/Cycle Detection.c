// A linked list is said to contain a cycle if any node is visited more than once while traversing the list.
//  Given a pointer to the head of a linked list, determine if it contains a cycle. If it does, return 1. Otherwise, return 0.

bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *slow, *fast;
    slow = fast = head;
   
    while(slow && fast && fast->next) {
        /* Slow pointer will move one node per iteration whereas 
        fast node will move two nodes per iteration */
        slow = slow->next;
        fast  = fast->next->next;
        // Cycle exists
        if (slow == fast) {
           return true;
        }
    }
    // Cycle does not exists
   return false;

}
