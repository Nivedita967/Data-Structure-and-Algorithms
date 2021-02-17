class Solution {
public:

//this is a struct used to sort priority queue in ascending order of value of nodes.
    struct node_cmp
{
   bool operator()( const ListNode* a, const ListNode* b ) const 
   {
    return a->val > b->val;
   }
};
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        //head and tail ptr to save the head and tail of final list
        ListNode* headptr=NULL;
        ListNode* tailptr=NULL;

        //priority queue to sort in ascending order
        priority_queue<ListNode*, vector<ListNode*>, node_cmp>pq;

        //pushing heads of all the lists to priority queue
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        }
        
        //taking one node (with min val) at a time and adding to the final list
        //also if the next to that removed node is not null then push that in priority queue

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

        //returning final headptr 
        return headptr;
    }
};