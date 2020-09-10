//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"
#include "LinkedList.cpp"

Node* swap_Nodes(Node *head,int i,int j)
{
    Node *Node1=NULL, *Node2=NULL, *Node1_prev=NULL, *Node2_prev=NULL, *temp=head, *prev=NULL;
    
    int count=0;
    while(temp!=NULL)
    {
        if(count==i){
            Node1_prev=prev;
            Node1=temp;
        }
        else if(count==j)
        {
            Node2_prev=prev;
            Node2=temp;
        }
        count++;
        prev=temp;
      	temp=temp->next;
    }
    
    if(Node1_prev==NULL){
        head=Node2;
    }
    else{
        Node1_prev->next=Node2;
    }
    
    if(Node2_prev==NULL){
        head=Node1;
    }
    else{
        Node2_prev->next=Node1;
    }
    
    temp=Node1->next;
    Node1->next=Node2->next;
    Node2->next=temp;
    
    return head;
    
}


int main(){
    LinkedList ll;
    ll.createLL();

    int m, n;
    cin>>m>>n;

    ll.head=swap_Nodes(ll.head, m, n);

    ll.printLL(ll.head);

}