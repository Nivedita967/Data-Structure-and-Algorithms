class Solution {
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if(head == NULL) {return head;}
        if(head->next == NULL) {return head;}
        //using two pointer approach - one for odd and other for even
        ListNode* odd = head;
        ListNode* even = head->next;
        //storing start of even to connect it to end of odd list
        ListNode* first_even = even;
        while(1)
        {
            //connecting even list when odd or even numbers are finished
            if(!odd || !even || !(even->next))
            {
                odd->next = first_even;
                break;
            }
            //jumping for odds
            odd->next = even->next;
            odd = even->next;
            //if odd is the last node then connect evens next to it.
            if(odd->next == NULL)
            {
                even->next = NULL;
                odd->next = first_even;
                break;
            }
            //jumping for evens
            even->next = odd->next;
            even=odd->next;
         }
         return head;
     }
};

/**
Example 1:

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
-------------------------
Example 2:

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
**/
