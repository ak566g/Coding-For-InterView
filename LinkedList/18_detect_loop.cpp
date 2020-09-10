//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"
#include "LinkedList.cpp"

bool detectLoop(Node* head)
{
    Node *slow=head, *fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        if(slow==fast)
        return true;
        
        slow=slow->next;
        fast=fast->next->next;
    }
    return false;
}


int main(){
    LinkedList ll1;
    ll1.createLL();

    ll1.head->next->next->next=ll1.head;

    cout<<detectLoop(ll1.head);

    cout<<endl;
    LinkedList ll2;
    ll2.createLL();

    cout<<detectLoop(ll2.head);

}