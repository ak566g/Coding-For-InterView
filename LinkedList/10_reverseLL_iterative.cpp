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
    Node *cur=head;
    Node *prev=NULL;
    Node *next=NULL;

    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head=prev;
    return head;
}

int main(){
    Node *head= createLL();
    head= reverseLL(head);
    cout<<endl;
    printLL(head);
}