SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
// Dynamically Intiallising The Variables

	 SinglyLinkedListNode*temp = head;
        SinglyLinkedListNode*n1 = new SinglyLinkedListNode(data);
//  If head == null then  just return the last created node
        if(head == NULL) {
            return n1;
        }
        // Looping through the values
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next  = n1;
        n1->next = NULL;
    //   Since Here the function type is of type head so will return the head of a Linked list
        return head;
}