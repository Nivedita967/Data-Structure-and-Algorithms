#include <bits/stdc++.h>

void printLinkedList(SinglyLinkedListNode* head) {
    // If Head = NULL Then Will Return Simply
    // Remember we can Never Access NULL Element it will result into RunTime Error
if(head==NULL)
return;
// Loop to print the elements
while(head!=NULL)
{
cout<<head->data<<endl;
head=head->next;
}
}
