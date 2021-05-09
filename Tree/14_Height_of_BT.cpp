class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        
        if(node==NULL){
            return 0;
        }
        
        int left = 1 + height(node->left);
        int right = 1 + height(node->right);
        
        return max(left, right);
    }
};