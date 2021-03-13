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
    
    int checkLevel(TreeNode *root, int &parent, int x){
        if(root==NULL){
            return -1;
        }
        
        if(root->left && root->left->val == x){
            parent=root->val;
            return 0;
        }
        if(root->right && root->right->val == x){
            parent=root->val;
            return 0;
        }
        
        int left = checkLevel(root->left, parent, x);
        int right = checkLevel(root->right, parent, x);
        
        if(left == -1 && right==-1){
            return -1;
        }
        
        else if(left!=-1){
            return 1+left;
        }
        
        else {
            return 1+right;
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int parent1=-1;
        int parent2=-1;
        
        int xLevel = checkLevel(root, parent1, x);
        int yLevel = checkLevel(root, parent2, y);
        
        if(xLevel==yLevel && parent1!=parent2){
            return true;
        }
        
        // cout<<xLevel<<" "<<yLevel<<" "<<parent1<<" "<<parent2;
        
        return false;
    }
};