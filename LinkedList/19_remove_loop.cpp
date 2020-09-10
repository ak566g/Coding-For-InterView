//Question Link.
//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

//Main catch is in the question in that, when slow moves x distance fast will move 2x distance.
// 1--> 2--->3--->4--->5--->6--->7--|
// -------a--|<--k-><-------b------>|
//           ------------------------

//distance covered by slow is a+k
//distance covered by fast is a+k+k+b

// 2*(a+k)==a+k+k+b
// a==b
// hence if we move slow to head, and then move fast and slow both by one steps, we'll get intersection point of loop.

void removeLoop(Node* head)
{
    if(head==NULL || head->next==NULL)
    return;
    
    Node *slow=head;
    Node *fast=head;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            break;
        }
        
    }
    
    if(slow==head){
            while(slow->next!=head){
            slow=slow->next;
        }
        slow->next = NULL;
    }
    
    if(slow==fast)
    {
        slow=head;
        
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        fast->next=NULL;
    }
    
    return;
}
