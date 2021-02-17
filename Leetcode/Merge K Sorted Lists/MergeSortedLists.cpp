class Solution {
public:
    struct node_cmp
{
   bool operator()( const ListNode* a, const ListNode* b ) const 
   {
    return a->val > b->val;
   }
};
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* headptr=NULL;
        ListNode* tailptr=NULL;
        priority_queue<ListNode*, vector<ListNode*>, node_cmp>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        }
        
        while(pq.size()!=0){
            ListNode* rptr= pq.top();
            pq.pop();
            if(headptr==NULL){
                headptr= rptr;
                tailptr= rptr;
            }
            else{
                tailptr->next = rptr; 
                tailptr= tailptr->next;
            }
            if(rptr->next!=NULL)
                pq.push(rptr->next);
            
        }
        return headptr;
    }
};