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
    
    unordered_map<TreeNode*, int>um;
    
    int rob(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        if(um.count(root)>0){
            return um[root];
        }
        
        int ans1 = 0;
        
        if(root->left && root->right)
            ans1= root->val + rob(root->left->left) + rob(root->left->right) + rob(root->right->left) + rob(root->right->right); 
        else if(root->left)
            ans1= root->val + rob(root->left->left) + rob(root->left->right);
        else if(root->right)
            ans1= root->val +  rob(root->right->left) + rob(root->right->right);
        else
            ans1 = root->val;
        int ans2 = rob(root->left) + rob(root->right);
        
        return um[root] = max(ans1, ans2);
    }
};