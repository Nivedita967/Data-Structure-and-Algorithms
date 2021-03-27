
// C program to swap nodes in pair of linked list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
  struct ListNode *p = NULL, *q = head, *temp;
  //checking whether the list is NULL or not
    if (head == NULL || head->next == NULL)
        return head;    
    p = head->next;   
    //While loop till head is NULL and then swap
    while(head != NULL && head->next != NULL)
    {
        temp = head->next->next;
        q->next = head->next;
        head->next->next = q = head;
        head->next = temp;
        head = head->next;
    }
    //return result
    return p;    
}

