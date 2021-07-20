//by Ankita Gupta
#include <bits/stdc++.h>
using namespace std;
class LinkedList
{
    public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }

    Node * createLL()
    {
        head=NULL, tail=NULL;

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

    Node * partitionLL(Node *head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        int val = head->data;
        Node* prev = head;
        Node* cur = head->next;

        while(cur){
            if(cur->data < val){
                Node* temp = cur;
                Node* temp2 = cur->next;
                prev -> next = cur -> next;
                temp->next = head;
                head = temp;
                cur = temp2;
            }else{
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }

    ~LinkedList()
    {
        delete head;
        delete tail;
    }
};