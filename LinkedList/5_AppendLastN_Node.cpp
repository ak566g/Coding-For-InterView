//by Ankita Gupta
// Finding nth node from last in one traversal.. take two pointers, first and second.. move second pointer till n.. then.. start moving 
// first and second simultaneously. 
// first will be at nth node from last.
// meanwhile take care of corner conditions.


#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node *appendLastNToFirst(Node *head, int n)
{
    Node* first=head;
    Node* second=head;
    Node* firstPrev=NULL;
    Node* secondPrev=head;
    int count=0;
    
    if(first!=NULL)
    {
        while(count<n)
        {
            if(second==NULL)
                return head;
            
            second=second->next;
            count++;
        }
        
        while(second!=NULL)
        {
            firstPrev=first;
            first=first->next;
            secondPrev=second;
            second=second->next;
        }
    }
    
    if(n!=0&&count==n)
    {
        firstPrev->next=NULL;
    	secondPrev->next=head;
    	return first;
    }
    
    return head;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}
