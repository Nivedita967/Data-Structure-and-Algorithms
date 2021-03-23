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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp){ //Track the k^th element.
            count++;
            temp = temp->next;
        }
        if (count == 0 || k == 0 || count == 1 || k % count == 0 ) return head;
        count -= (k%count); //we take mod count because k could be greater than length of linked list and rotating the LL for its own length time results in the same list.
        temp = head;
        ListNode * q = NULL;
        while (count--){ //Track the kth element
            q = temp;
            temp = temp->next;
        }
        q->next = NULL; 
        ListNode * p;
        p = temp;
        while (temp->next && temp){ //Attach the remaining list after k^th element to the begining;
            temp = temp->next;
        }
        temp->next = head;
        return p;
    }
};