//Problem:https://leetcode.com/problems/odd-even-linked-list/

struct ListNode* oddEvenList(struct ListNode* head) {
    // create a start node 
    struct ListNode* start = malloc(sizeof(struct ListNode));
    start->next = head;
    
    struct ListNode* odd = start, * curpre = start, * cur = head;
    bool isodd = true;
    while (cur != NULL) {
        if (isodd && odd->next != cur) {
            // if cur is odd, cur should be moved to odd's next
            curpre->next = cur->next;
            cur->next = odd->next;
            odd->next = cur;
            cur = curpre->next;
            odd = odd->next;
        } else {
            // if cur is odd but odd's next is already pointed to cur, 
            // nothing will be changed, just move the odd pointer
            odd = isodd ? odd->next : odd;
            curpre = cur;
            cur = cur->next;
        }
        isodd = !isodd;
    }
    return start->next;
}
