class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    void helper(Node *root, Node* &head, Node* &prev){
        if(root==NULL){
            return;
        }
        
        helper(root->left, head, prev);
        
        if(head==NULL){
            prev = root;
            head = root;
        }else{
            prev->right=root;
            prev->right->left = prev;
            prev = prev->right;
        }
        
        helper(root->right, head, prev);
    }
    
    Node * bToDLL(Node *root)
    {
        Node * head = NULL, *prev=NULL;
        helper(root, head, prev);
        return head;
    }
};
