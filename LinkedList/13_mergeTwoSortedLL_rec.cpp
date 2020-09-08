//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"
#include "LinkedList.cpp"

Node *mergeSortedLL(Node *head1, Node *head2)
{
    if(head2==NULL)
    return head1;

    if(head1==NULL)
    return head2;

    if(head1->data<head2->data)
    {
        head1->next=mergeSortedLL(head1->next,head2);
    }
    else
    {
        head2->next=mergeSortedLL(head1,head2->next);
    }
   
}

int main(){
    LinkedList ll1;
    ll1.createLL();
    
    LinkedList ll2;
    ll2.createLL();

    Node* head=mergeSortedLL(ll1.head, ll2.head);

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}