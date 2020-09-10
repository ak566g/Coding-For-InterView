//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"
#include "LinkedList.cpp"

Node* skipMdeleteN(Node  *head, int M, int N) {
    Node *temp=head;
    
    while(temp!=NULL)
    {
        int i=1, j=0;
        while(i<M && temp!=NULL){
            temp=temp->next;
            i++;
        }
        
        if(temp==NULL)
            return head;
        
        while(j<N && temp!=NULL && temp->next!=NULL)
        {
            Node *todelete= temp->next;
            temp->next=temp->next->next;
            delete todelete;
            j++;
        }
        temp=temp->next;
    }
    if(M==0)
        return NULL;
    
    return head;
}


int main(){
    LinkedList ll;
    ll.createLL();

    int m, n;
    cin>>m>>n;

    ll.head=skipMdeleteN(ll.head, m, n);

    ll.printLL(ll.head);

}