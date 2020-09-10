// https://leetcode.com/problems/copy-list-with-random-pointer/


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