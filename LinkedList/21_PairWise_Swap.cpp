//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"
#include "LinkedList.cpp"

Node * pairWiseSwap(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;

    Node *remaining = head->next->next;
    Node *newHead=head->next;

    head->next->next=head;
    head->next=pairWiseSwap(remaining);
    
    return newHead;
}

int main(){
    LinkedList ll;
    ll.createLL();

    ll.head=pairWiseSwap(ll.head);
    cout<<endl;
    ll.printLL(ll.head);
}