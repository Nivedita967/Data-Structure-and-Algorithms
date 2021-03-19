/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null)
            return null;
        ListNode curr = head;
        int len = 1;

        //while loop until we traverse complete list
        //and find the length
        while(curr.next!=null) {
            curr = curr.next;
            len++;
        }
        curr.next = head;
        k%=len;
        for(int i=0;i<len-k;i++) {
            curr = curr.next;
        }
        
        //changing the head to make it new head
        head= curr.next;
        curr.next= null;
        
        return head;
    }
}

