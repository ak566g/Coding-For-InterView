//by Ankita Gupta

#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;


Node * createLL()
{
    Node* head=NULL, *tail=NULL;

    int data;
    cin>>data;
    
    while(data!=-1)
    {
        Node *temp= new Node(data);

        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
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

Node* delete_ith_Node(Node *head, int i)
{
    if(head==NULL)
    return NULL;

    if(i==0)
    {
        head=head->next;
        return head;
    }

    Node *temp=head, *prev=NULL;
    while(temp!=NULL && i>0)
    {
        prev=temp;
        temp=temp->next;
        i--;
    }

    if(temp!=NULL)
    {
        prev->next=temp->next;
    }

    return head;
}

int main(){
    Node *head= createLL();
    int i;
    cin>>i;

    head=delete_ith_Node(head,i);

    printLL(head);
}