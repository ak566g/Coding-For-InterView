//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"
#include "LinkedList.cpp"

int midPoint(Node *head)
{
    Node *slow=head, *fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    return slow->data;
}

int main(){
    LinkedList ll;
    ll.createLL();
    
    cout<<midPoint(ll.head);
}