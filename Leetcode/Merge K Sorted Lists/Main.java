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
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        for(ListNode node: lists) {
            if(node == null) continue;
            pq.offer(node);
        }
        
        ListNode dummy = new ListNode();
        ListNode pre = dummy;
        while(pq.size() > 0) {
            ListNode next = pq.poll();
            pre.next = next;
            pre = pre.next;
            if(next.next != null) pq.offer(next.next);
        }
        
        return dummy.next;

    }
}
