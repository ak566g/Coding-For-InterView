class Solution {
  public:
    int helper(Node *root){
        if(root==NULL){
            return 0;
        }
        
        int curNode = root->data;
        int left = helper(root->left);
        int right = helper(root->right);
        
        root->data = left+right;
        
        return curNode+left+right;
    }
    
    void toSumTree(Node *root)
    {
        helper(root);
    }
};