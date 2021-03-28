
// C program to remove nth node from end of list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
   register int count = 0;
    struct ListNode* q,* p = head;
    //counting the length of the list
    while(p != NULL)
    {
        count++;
        p = p->next;
    }
    count = count - n - 1;
    //If count is less than zero then eliminate the first node
    if(count < 0)
    {
        q = head;
        head = q->next;
    }
    //If count is greater than zero then the following operation is done
    else
    {
        p = head;
        for(register int i = 0; i < count; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
    }
    free(q);
    //return the list
    return head;
}

