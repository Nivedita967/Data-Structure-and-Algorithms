class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {

        // Creating a new variable temp of type ListNode
        ListNode temp = new ListNode();
        temp = head;
        int len = 0;
        // Pointing temp to the end of the linked list
        while(temp != null){
            len++;
            temp = temp.next;
        }
        // Effective value of n from the start of the list
        int eff = len - n + 1;
        ListNode p = head;
        int count = 1;
        ListNode q = head;
        if(len == 1)
            return temp;
        
        if(eff == 1){
            return head.next;
        }
        
        // Traverse till we reach one node before the Nth node.
        while(count < eff - 1){
            p = p.next;
            count++;
        }
        // Bypassing the node
        p.next = p.next.next;
        return head;
    }
}