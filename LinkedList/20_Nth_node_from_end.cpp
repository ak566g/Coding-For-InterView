//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"
#include "LinkedList.cpp"

int getNthFromLast(Node *head, int n)
{
    int count=0;
    
    Node *slow=head, *fast=head;
    
    while(fast!=NULL)
    {
        while(count<n && fast!=NULL)
        {
            count++;
            fast=fast->next;
        }
        if(fast==NULL && count<n)
        return -1;
        
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    
    return slow->data;
}



int main(){
    LinkedList ll;
    ll.createLL();

    int n;
    cin>>n;

    cout<<getNthFromLast(ll.head, n);
}