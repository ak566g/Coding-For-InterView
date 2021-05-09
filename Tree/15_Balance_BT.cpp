class Solution {
public:
    
    int height(TreeNode* root){
        if(root==NULL)return 0;
        
        return 1+max(height(root->left), height(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return leftAns && rightAns && abs(lh-rh)<=1;
    }
};