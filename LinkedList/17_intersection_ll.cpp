//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"
#include "LinkedList.cpp"

int intersectPoint(Node* head1, Node* head2)
{
    int size1=0, size2=0;
    Node *temp1=head1, *temp2=head2;
    
    while(temp1!=NULL){
        size1++;
        temp1=temp1->next;
    }
    
    while(temp2!=NULL)
    {
        size2++;
        temp2=temp2->next;
    }
    
    temp1=head1;
    temp2=head2;
    
    if(size1>size2)
    {
        int c=size1-size2;
        
        while(c--)
        {
            temp1=temp1->next;
        }
    }
    else
    {
        int c=size2-size1;
        
        while(c--)
        {
            temp2=temp2->next;
        }
    }
    
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1==temp2)
        {
            return temp1->data;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    
    return -1;
}


int main(){
    LinkedList ll1;
    ll1.createLL();

    LinkedList ll2;
    ll2.createLL();

    //This is intersection point, just for checking...
    ll1.head->next->next=ll2.head->next->next;

    cout<<intersectPoint(ll1.head, ll2.head);


}