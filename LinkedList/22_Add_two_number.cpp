//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"
#include "LinkedList.cpp"

Node *reverseList(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    Node *remaining= reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return remaining;
    
    
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    first=reverseList(first);
    second=reverseList(second);
    
    Node *head=NULL;
    Node *tail=NULL;
    int carry=0;
    
    while(first!=NULL && second!=NULL)
    {
        Node *newNode=new Node(first->data + second->data+carry);
        carry=(newNode->data)/10;
        newNode->data= (newNode->data)%10;
        first=first->next;
        second=second->next;
        
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
        
    }
    
    while(first!=NULL)
    {
        Node *newNode=new Node(first->data +carry);
        carry=(newNode->data)/10;
        newNode->data= (newNode->data)%10; 
        first=first->next;
        
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
    }
    
    while(second!=NULL)
    {
        Node *newNode=new Node(second->data +carry);
        carry=(newNode->data)/10;
        newNode->data= (newNode->data)%10; 
        second=second->next;
        
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
    }
    
    while(carry>0)
    {
        Node *newNode=new Node(carry);
        carry=(newNode->data)/10;
        newNode->data= (newNode->data)%10; 
        
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
    }
    
    head=reverseList(head);
    return head;
}

int main(){
    LinkedList ll1;
    ll1.createLL();
    
    LinkedList ll2;
    ll2.createLL();

    Node* head=addTwoLists(ll1.head, ll2.head);

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}