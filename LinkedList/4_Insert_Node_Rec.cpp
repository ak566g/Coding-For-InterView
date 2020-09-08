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

Node* insert_at_ith(Node *head, int pos, int data)
{
    Node *newNode = new Node(data);
    if(pos==0)
    {
        newNode->next=head;
        head=newNode;
        return head;
    }

    Node *cur=head;
    Node *prev=head;

    while(pos--&&cur!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }

    prev->next=newNode;
    newNode->next=cur;

    return head;
}

Node *insertRecursive(Node *head , int pos, int data)
{
    if(pos==0)
    {
        Node *newNode = new Node(data);
        newNode->next=head;
        return newNode;
    }
    
    if(head==NULL)
    {
        return NULL;
    }

    head->next= insertRecursive(head->next,pos-1,data);
}

int main(){
    Node *head= createLL();
    int i;
    cin>>i;
    int data;
    cin>>data;

    //head= insert_at_ith(head,i,data);

    head=insertRecursive(head,i,data);
    cout<<endl;
    printLL(head);
    return 0;
}