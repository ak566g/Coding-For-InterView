//by Ankita Gupta

#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node* createLL()
{
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1)
    {
        Node *newNode = new Node(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=tail->next;
        }
        
        cin>>data;
    }

    return head;
}


void printLL(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}

Node *reverseLL(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;

    Node *remaining = reverseLL(head->next);
    head->next->next=head;
    head->next=NULL;

    return remaining;
}

int main(){
    Node *head= createLL();
    head= reverseLL(head);
    cout<<endl;
    printLL(head);
}