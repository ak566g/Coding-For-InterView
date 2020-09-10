//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"
#include "LinkedList.cpp"


Node* segregate(Node *head) {
    Node *oneH=NULL, *oneT=NULL, *twoH=NULL, *twoT=NULL, *zeroH=NULL, *zeroT=NULL;
    Node *temp=head;
    
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            if(zeroH==NULL)
            {
                zeroH=temp;
                zeroT=temp;
            }
            else
            {
                zeroT->next=temp;
                zeroT=zeroT->next;
            }
        }
        
        else if(temp->data==1)
        {
            if(oneH==NULL)
            {
                oneH=temp;
                oneT=temp;
            }
            else
            {
                oneT->next=temp;
                oneT=oneT->next;
            }
        }
        
        else if(temp->data==2)
        {
            if(twoH==NULL)
            {
                twoH=temp;
                twoT=temp;
            }
            else
            {
                twoT->next=temp;
                twoT=twoT->next;
            }
        }
        
        temp=temp->next;
    }
    
    if(zeroH)
    {
        zeroT->next=NULL;
    }
    if(oneH)
    {
        oneT->next=NULL;
    }
    
    if(twoH)
    {
        twoT->next=NULL;
    }
    
    
    if(zeroH!=NULL && oneH!=NULL)
    {
        zeroT->next=oneH;
    }
    if(oneH!=NULL && twoH!=NULL)
    {
        oneT->next=twoH;
    }
    
    if(oneH==NULL && zeroT!=NULL && twoH!=NULL)
    {
        zeroT->next=twoH;
    }
    
    if(zeroH!=NULL)
    return zeroH;
    
    if(oneH!=NULL)
    return oneH;
    
    return twoH;
    
}



int main(){
    LinkedList ll;
    ll.createLL();
    
    ll.head=segregate(ll.head);
    cout<<endl;
    ll.printLL(ll.head);
    
}