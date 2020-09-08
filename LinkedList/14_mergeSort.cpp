//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"
#include "LinkedList.cpp"

Node* midLL(Node *head)
{
    Node *slow=head;
    Node *fast=head->next;
    
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    return slow;
}

Node *mergeSortedLL(Node *head1, Node *head2)
{
    if(head1==NULL)
        return head2;
    
    if(head2==NULL)
        return head1;
    
    if(head1->data<head2->data)
        head1->next=mergeSortedLL(head1->next,head2);
    else
        head2->next=mergeSortedLL(head1,head2->next);
    
    
}

Node* mergeSort(Node *head) {
    if(head==NULL || head->next==NULL)
        return head;
    
    Node *mid= midLL(head);
    Node *temp=mid->next;
    mid->next=NULL;
    head=mergeSort(head);
    temp=mergeSort(temp);
    head=mergeSortedLL(head,temp);
    return head;
}


int main(){
    LinkedList ll;
    ll.createLL();
    
    ll.head=mergeSort(ll.head);

    ll.printLL(ll.head);
}