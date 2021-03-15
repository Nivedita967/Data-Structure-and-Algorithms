/**
 * Problem Statement:
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */



public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
       
        int carry = 0;
        ListNode dummy = new ListNode();
        ListNode pre = dummy;
        while(l1 != null && l2 != null){
        
            int temp = l1.val + l2.val + carry;
            carry = 0;
           if(temp > 10){
               int n = temp % 10;
               carry = temp / 10;
               temp = n;
           }
           else if(temp == 10){
               
               temp = 0;
               carry = 1;
               
            }
           
            ListNode run = new ListNode(temp,null);
             pre.next = run;
            pre = pre.next;
            
       
            l1= l1.next;
            l2 = l2.next;
        }
        
        if(l1 != null){
            while(l1 != null){
                  int temp = l1.val + carry;
           carry = 0;
            if(temp > 10){
               int n = temp % 10;
               carry = temp / 10;
               temp = n;
           }
           else if(temp == 10){
              
               temp = 0;
               carry = 1;
               
            }
            
           
            ListNode run = new ListNode(temp,null); 
            pre.next = run;
            pre = pre.next;
            
            l1 = l1.next;
            }
        }
        else if(l2 != null){
            while(l2 != null){
                  int temp = l2.val + carry;
           carry = 0;
            if(temp > 10){
               int n = temp % 10;
               carry = temp / 10;
               temp = n;
           }
           else if(temp == 10){
              
               temp = 0;
               carry = 1;
               
            }
            
           
            ListNode run = new ListNode(temp,null); 
            pre.next = run;
            pre = pre.next;
            
            l2 = l2.next;
            }
        }
        
         if(carry > 0){
             ListNode run = new ListNode(carry,null);
            pre.next = run;
        }
        
        return dummy.next;
        
       
    }
    
}
