struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int a=0,b=0;    
    struct ListNode* p=NULL, *head=NULL;
    while(l1!=NULL && l2!=NULL) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->next=NULL;
        a=l1->val + l2->val + b;
        b=a/10;
        node->val=a%10;

        if(p==NULL){
            p=node;
            head=p;
        }else{
            p->next=node;
            p=p->next;
        }

        l1=l1->next;
        l2=l2->next;
    }
    
    while(l1!=NULL) {    // If the l1 List containes elements, add those elements in the result list
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->next=NULL;
        a=l1->val+b;
        b=a/10;
        node->val=a%10;
        p->next=node;
        p=p->next;
        l1=l1->next;
    }
    while(l2!=NULL) {   // If the l2 List containes elements, add those elements in the result list
        struct ListNode * node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->next=NULL;
        a=l2->val+b;
        b=a/10;
        node->val=a%10;
        p->next=node;
        p=p->next;
        l2=l2->next;
    }
    if(b>0){    // When there is preceding bit in remqainder, need to add it in new node.
        struct ListNode * node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->next=NULL;
        node->val=b;
        p->next=node;
        p=p->next;
    }

    return head;
}