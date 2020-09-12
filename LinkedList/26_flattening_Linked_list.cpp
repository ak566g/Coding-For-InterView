// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/submissions/
// https://www.youtube.com/watch?v=F-oPHhK1em0
//Flatten Linked list depth wise
/*


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *ans;
    Node* flatten(Node* head) {
        ans=head;
        
        stack<Node *>st;
        
        Node *cur=head;
        Node *tail=NULL;
        while(cur!=NULL)
        {
            if(cur->child!=NULL)
            {
                Node *child=cur->child;
                
                if(cur->next!=NULL)
                { 
                    st.push(cur->next);
                    cur->next->prev=NULL;
                }
                
                cur->next=child;
                child->prev=cur;
                cur->child=NULL;
            }
            tail=cur;
            cur=cur->next;
        }
        
        while(!st.empty())
        {
            cur=st.top();
            tail->next=cur;
            cur->prev=tail;
            
            while(cur!=NULL)
            {
                tail=cur;
                cur=cur->next;
            }
            st.pop();
        }
        
        return head;
    }
};