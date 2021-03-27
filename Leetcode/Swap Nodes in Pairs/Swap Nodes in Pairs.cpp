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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head; // if list is empty, return head i.e is null

        ListNode* temp = head;
        int key;
        while (temp && temp->next){

            //normal swap algo
            key = temp->val;
            temp->val = temp->next->val;
            temp->next->val = key;

            //advance the pointer by two
            temp = temp->next->next;
        }
        return head;
    }
};