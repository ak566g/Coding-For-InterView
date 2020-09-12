// https://leetcode.com/problems/copy-list-with-random-pointer/

// This is the one of the trickiest question of linked list.
// This question can be solved using hashmap in which we create map of given linked list node to 
// new linked list node, and then traverse in list, and maintain random and next pointer of new list using map.
// But this is O(n) space complexity approach.

// For reducing the space complexity,
// In this question we change the pointer of given list also, basically what we try to do is inserting new cloned node next to the original node.
// And then modify random pointer of new linked list with the help of old list.
// And then again recover the changes of original list.

// Algo:
// Traverse in original linked list let say with pointer current.
// Store current->next in temporay pointer.
// create a new node with data of current node and link it to current->next
// and now make newnode->next = temp
// move current pointer to next position i.e. temp.

// after this we have created all the list nodes.

// now for mainting random pointer again traverse in original list and put current->next->random= current->random->next 
// and meanwhile take care of Null conditions.

// Now for removing the link for first list to second list..
// do 
// current->next = current->next->next;
// copiedList->next= copiedList->next->next

// and move in both the lists.


class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL)
            return NULL;
        
        Node *current=head;
        Node *temp;
        
        while(current!=NULL)
        {
            temp=current->next;
            current->next=new Node(current->val);
            current->next->next=temp;
            current=temp;
        }
        
        current=head;
        
        while(current!=NULL)
        {
            if(current->next!=NULL)
            {
                if(current->random!=NULL){
                    current->next->random=current->random->next;
                }
                else
                {
                    current->next->random=current->random;
                }
            }
            
            
            if(current->next!=NULL)
            {
                current=current->next->next;
            }
            else
            {
                current=current->next;
            }
        }
        
        Node *ans=head->next;
        Node *original=head;
        temp=ans;
        
        while(original!=NULL && ans!=NULL)
        {
            if(original->next!=NULL)
            {
                original->next=original->next->next;
            }
            else
            {
                original->next=original->next;   
            }
            
            if(ans->next!=NULL)
            {
                ans->next=ans->next->next;
            }
            else
            {
                ans->next=ans->next;
            }
            
            original=original->next;
            ans=ans->next;
        }
        
        return temp;
    }
};