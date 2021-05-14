/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int ans = 0;
    
    void helper(TreeNode* root, int lr, int len){
        ans = max(ans, len);
        
        if(lr==1){  // zig to left and dir will be 0
            if(root->left){
                helper(root->left, 0, len+1);
            }
            if(root->right){
                helper(root->right, 1, 1);
            }
        }
        
        if(lr==0){      // zig to right, and dir will be 1
            if(root->right){
                helper(root->right, 1, len+1);
            }
            if(root->left){
                helper(root->left, 0, 1);
            }
        }
    }
    
    int longestZigZag(TreeNode* root) {
        
        if(root->left)
            helper(root->left, 0, 1);
        
        if(root->right)
            helper(root->right, 1, 1);
        
        return ans;
    }
};