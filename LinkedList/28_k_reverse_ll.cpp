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

Node *reverse(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    Node *remaining= reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return remaining;
}

Node *reverse (Node *head, int k)
{ 
    if(head==NULL)
    return head;
    
    int count=1;
    Node *cur=head;
    
    while(cur->next!=NULL &&  count<k)
    {
        cur=cur->next;
        count++;
    }
    
    Node *remaining= cur->next;
    cur->next=NULL;
    head=reverse(head);
    
    cur=head;
    while(cur->next!=NULL)
    cur=cur->next;
    
    
    cur->next=reverse(remaining,k);
    return head;
}

int main(){
    Node *head= createLL();
    int n;
    cin>>n;

    head=reverse(head,n);

    cout<<endl;
    printLL(head);
}