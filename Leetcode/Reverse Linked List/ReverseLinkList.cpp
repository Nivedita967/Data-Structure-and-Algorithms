class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        //three pointer approach
        ListNode* p=head;  // curr head
        ListNode* q=head;  // intermediate node
        ListNode* r=NULL;  // final head

        //while loop until we traverse complete list
        while(q!=NULL){
            q=p->next;
            p->next=r;
            
            r=p;
            p=q;
        }

        //changing the head to make it new head
        head=r;
        return head;
    }
};