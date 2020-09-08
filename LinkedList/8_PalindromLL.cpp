//by Ankita Gupta

#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node *reverse(Node *head)
{
    if(head==NULL||head->next==NULL)
        return head;
    
    Node *remaining= reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return remaining;
    
}

bool isPalindrome(Node *head)
{
    
    if(head==NULL||head->next==NULL)
        return true;
    
    Node *slow=head;
    Node *fast=head;
    Node *prevSlow=head;
    
    while(fast!=NULL&&fast->next!=NULL)
    {
        prevSlow=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    Node *head1, *head2;
    
    if(fast==NULL)
    {
        head2=slow;
        prevSlow->next=NULL;
    }
    else
    {
        head2=slow->next;
        prevSlow->next=NULL;
    }
    
    head=reverse(head);
    
    while(head!=NULL&&head2!=NULL)
    {
        if(head->data!=head2->data)
            return false;
        head=head->next;
        head2=head2->next;
    }
    
    return true;
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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}