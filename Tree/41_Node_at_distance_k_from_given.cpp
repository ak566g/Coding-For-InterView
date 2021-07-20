/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int>ans;
    
    void kd(TreeNode* root, int k){
        if(root==NULL){
            return;
        }
        
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        
        kd(root->left, k-1);
        kd(root->right, k-1);
    }
    
    int helper(TreeNode* root, TreeNode* target, int k){
        if(root==NULL){
            return -1;
        }
        
        if(root==target){
            kd(root, k);
            return 0;
        }
        
        int left = helper(root->left, target, k);
        int right = helper(root->right, target, k);
        
        if(left!=-1){
            if(left+1 == k){
                ans.push_back(root->val);
            }else{
                kd(root->right, k-left-2);
            }
            return 1+left;
        }
        
        if(right!=-1){
            if(right+1==k){
                ans.push_back(root->val);
            }else{
                kd(root->left, k-right-2);
            }
            return 1+right;
        }
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        helper(root, target, k);
        return ans;
    }
};