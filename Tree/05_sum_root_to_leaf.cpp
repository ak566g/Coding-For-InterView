// https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution {
public:
    vector<int>path;
    
    void helper(TreeNode* root, int p){
        if(root==NULL){
            cout<<p<<" ";
            return;
        }
        
        p = p*10 + root->val;
        
        if(root->left==NULL && root->right==NULL){
            path.push_back(p);
        }
        
        helper(root->left, p);
        helper(root->right, p);
    }
    
    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        int sum=0;
        for(int i=0;i<path.size();i++){
            sum+=path[i];
        }
        return sum;
    }
};