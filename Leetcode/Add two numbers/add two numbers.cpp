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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        queue<int> nums1,nums2,ans; //Two queues to copy all digits from linked list l1 and l2.
        while (l1){
            nums1.push(l1->val);
            l1=l1->next;
        }
        while (l2){
            nums2.push(l2->val);
            l2=l2->next;
        }
        int carry=0;  //will store the carry over from each addition.
        int mid=0; //will store the result of addition of two digits.
        while( !nums1.empty()|| !nums2.empty()){
            if (!nums1.empty()&& !nums2.empty()){ // if neither of the queues are empty add the digits.
                mid=nums1.front()+nums2.front()+carry;
                ans.push(mid%10);
                nums1.pop();
                nums2.pop();
                carry=mid/10;
            }
            else if (nums1.empty()){
                mid=nums2.front()+carry;
                ans.push(mid%10);
                nums2.pop();
                carry=mid/10;
            } 
            else {
                mid=nums1.front()+carry;
                ans.push(mid%10);
                nums1.pop();
                carry=mid/10;
            }
        }
        if (carry){
            ans.push(carry); //If carry still left after the last operation push it into the answer queue.
        }

        //Now copy the values from queue to a new linked list.
        ListNode*p;
        ListNode*root=new ListNode;
        root->val=ans.front();
        root->next=NULL;
        ans.pop();
        p=root;
        p->next=NULL;
        while(!ans.empty()){
            //cout<<n.front();
            ListNode*t=new ListNode;
            t->val=ans.front();
            ans.pop();
            t->next=NULL;
            p->next=t;
            p=t;
            //delete t;
        }
        return root;
    }
};