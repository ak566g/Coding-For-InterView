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
    
    
    vector<TreeNode*> helper(int l, int r){
        if(l==r){
            TreeNode* ans = new TreeNode(l);
            return {ans};
        }
        
        if(l>r){
            return {NULL};
        }
        
        vector<TreeNode*> ans;
        
        for(int i=l; i<=r; i++){
            vector<TreeNode*> left = helper(l, i-1);
            vector<TreeNode*> right = helper(i+1, r);
            
            for(auto l: left){
                for(auto r: right){
                    TreeNode *cur = new TreeNode(i);
                    cur->left = l;
                    cur->right = r;
                    ans.push_back(cur);
                }
            }
        }
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};