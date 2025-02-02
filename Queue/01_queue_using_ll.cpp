//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template<typename T>
class Queue {
    
    
    public :
    Node<T> * head;
    Node<T> *tail;
    int size;
    
    Queue() {
        head=NULL;
        tail=NULL;
        size=0;
    }
    
    void enqueue(T data) {
        Node<T> *newNode= new Node<T>(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=tail->next;
        }
        size++;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    T dequeue() {
        // Return 0 if queue is empty
        if(size==0)
            return 0;
        
        T ans=head->data;
        if(size==1)
        {
            head=NULL;
            tail=NULL;
        }
        else{
            head=head->next;
        }
        size--;
        return ans;
        
    }
    
    T front()  {
        // Return 0 if queue is empty
        if(size==0)
            return 0;
        return head->data;
    }
};


int main() {
    
    Queue<int> q;
    
    int choice;
    cin >> choice;
    int input;
    
    while (choice !=-1) {
        if(choice == 1) {
            cin >> input;
            q.enqueue(input);
        }
        else if(choice == 2) {
            int ans = q.dequeue();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 3) {
            int ans = q.front();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 4) {
            cout << q.getSize() << endl;
        }
        else if(choice == 5) {
            if(q.isEmpty()) {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
        cin >> choice;
    }
    
}
