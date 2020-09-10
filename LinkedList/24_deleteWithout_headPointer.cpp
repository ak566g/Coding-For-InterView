//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"
#include "LinkedList.cpp"

// void deleteNode(Node *node)
// {
//     if(node->next==NULL)
//     {
//         node=NULL;
//         return;
//     }

//     node->data=node->next->data;
//     Node *toDelete=node->next;
//     node->next=node->next->next;
//     delete toDelete;
// }

void deleteNode(Node *node)
{
   
    *(node)=*(node->next);
}

int main(){
    LinkedList ll;
    ll.createLL();
    
    deleteNode(ll.head->next->next);

    cout<<endl;

    ll.printLL(ll.head);
    
}