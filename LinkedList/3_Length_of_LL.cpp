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

int length(Node *head) {
    if(head==NULL)
        return 0;
    
    return 1+ length(head->next);
}

int main(){
     Node *head= createLL();
     cout<<length(head);

    return 0;
}