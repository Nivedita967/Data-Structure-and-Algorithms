class Solution {
    public ListNode swapPairs(ListNode head) {
        // initialize a variable of type ListNode
        ListNode temp = new ListNode();
        // if there is 0 or only one node return head node.
        if(head == null || head.next == null)
            return head;
        //  Initialize p to head & q to next of head.
        ListNode p = head;
        ListNode q = p.next;
        head = q;
        while(true){
            // Swapping algo
            temp = q.next;
            q.next = p;
            
             if(temp == null){ //for even list
                p.next = null;
                break;
            }
            if(temp.next == null){ // for odd list
                p.next = temp;
                break;
            }
            p.next = temp.next;
            p=temp;
            q=p.next;
            
            
        }
        // answer head
        return head;
    }
}