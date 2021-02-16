class Solution {
public:
    int ans = INT_MIN;    
    
    int helper(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        
        int left = helper(root->left);
        int right = helper(root->right);
        
        ans = max(ans, max(root->val,left+root->val));
        ans = max(ans, max(root->val,right+root->val));
        ans = max(ans, left+right+root->val);        
        
        return max(root->val + max(left, right), root->val);
    }
    
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};