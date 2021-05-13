class Solution
{
    public:
    
    bool ans = true;
    
    int helper(Node *root){
        if(root==NULL){
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL){
            return root->data;
        }
        
        int leftSum = helper(root->left);
        int rightSum = helper(root->right);
        
        if((leftSum + rightSum) != root->data){
            ans = false;
        }
        
        return leftSum + rightSum + root->data;
    }
    
    bool isSumTree(Node* root)
    {
         ans = true;
         if(root==NULL){
             return true;
         }
         helper(root);
         return ans;
    }
};