
class Node
{
  public:
    int data;
    int next;
    Node (int data)
    {
        this->data=data;
        next=NULL;
    }
};


class Stack {
	// Define the data members
    
   public:
    int size;
    Node* front;
    
    Stack() {
        // Implement the Constructor
        size=0;
        front=NULL;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return size==0;
    }

    void push(int element) {
        // Implement the push() function
        Node* node = new Node(element);
        if(size==0)
            front=node;
        else
        {
            node->next=front;
            front=node;
        }
        size++;
    }

    int pop() {
        // Implement the pop() function
        if(size==0)
            return -1;
        
        size--;
        int ans=front->data;
        front=front->next;
        return ans;
    }

    int top() {
        // Implement the top() function
        if(size==0)
            return -1;
        
        return front->data;
    }
};