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
class Solution 
{
    /* Here we create 2 linked lists, one containing all odd nodes and other containing all even nodes of given Linked List (LL).
	Then we connect the last node of the odd LL with the head node of the even LL. */
    public ListNode oddEvenList(ListNode head) 
{
        if(head==null)					//list is empty
        {
            return null;
        }
        ListNode odd = head;				//head of given LL as well as odd LL
        ListNode even = head.next;			//head of even LL
        ListNode evenHead = even;			//head of even LL
        while(even!=null && even.next!=null)		//traversing LL till we reach end of LL
        {
            odd.next = even.next;			//next node of odd list = node next to the even node of given LL
            odd = odd.next;				//next node of odd list
            even.next = odd.next;			//next node of even list = node next to the odd node of given LL
            even = even.next;				//next node of even list
        }
        odd.next = evenHead;				//node next to last node of odd list = head node of even list
        return head;					//return reordered list
    }
}