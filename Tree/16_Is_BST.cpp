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
    
    bool helper(TreeNode* root, TreeNode *curMin, TreeNode *curMax){
        if(root==NULL)return true;
        
        if(curMin!=NULL && root->val<=curMin->val)
            return false;
        
        if(curMax!=NULL && root->val>=curMax->val)
            return false;
        
        return helper(root->left, curMin, root) && helper(root->right, root, curMax);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};