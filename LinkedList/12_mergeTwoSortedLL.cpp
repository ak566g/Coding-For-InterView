//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"
#include "LinkedList.cpp"

Node *mergeSortedLL(Node *head1, Node *head2)
{
    Node *head=NULL;
	Node *tail=NULL;
    
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<=head2->data)
        {
            if(head==NULL)
            {
                head=head1;
                tail=head1;
            }
            else
            {
                tail->next=head1;
                tail=tail->next;
            }
            head1=head1->next;
        }
        else{
            
            if(head==NULL)
            {
                head=head2;
                tail=head2;
            }
            else
            {
                tail->next=head2;
                tail=tail->next;
            }
            head2=head2->next;
        }
    }
    
    if(head1==NULL)
    {
        tail->next=head2;
    }
    
    if(head2==NULL)
    {
        tail->next=head1;
    }
    
    return head;
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