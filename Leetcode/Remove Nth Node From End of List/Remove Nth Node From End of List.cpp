/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode*p=head;

        //advance the pointer to the end to count the number of nodes
        while(p){
            count++;
            p=p->next;
        }

        // if count is 1, then only one node is present, just delete that
        if (count==1){
            delete p;
            return NULL;
        }


        p=head;
        int i=count-n-1;

        if (n==count){
            head=head->next;
            delete p;
            return head;
        }

        //advance the pointer to one node before the node to be deleted.
        while(i--){
            p=p->next;
        }
        //deletion of node.
        ListNode*t=p->next;
        p->next=t->next;
        delete t;
        return head;
    }
};