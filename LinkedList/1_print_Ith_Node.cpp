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

int ith_Node(Node *head, int i)
{
    while(i>0 && head!=NULL)
    {
        head=head->next;
        i--;
    }
    
    if(head!=NULL)
    cout<<head->data;

}

int main()
{
    Node *head = createLL();

    int i;
    cin>>i;
    cout<<ith_Node(head,i);
    
}