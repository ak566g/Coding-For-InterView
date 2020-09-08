//by Ankita Gupta

#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node *removeDuplicates(Node *head)
{
    Node *temp= head;
    
    while(temp!=NULL)
    {
        while(temp->next!=NULL && temp->data==temp->next->data)
        {
            Node *toDelete=temp->next;
            temp->next=temp->next->next;
            delete toDelete;
        }
        temp=temp->next;
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
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}