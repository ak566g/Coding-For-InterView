class Solution
{
    public:
    void helper(Node *root, int &k, int &ans){
        if(k<=0 ||root==NULL){
            return;
        }
        
        helper(root->right, k, ans);
        k--;
        if(k==0){
            ans = root->data;
        }
        
        helper(root->left, k, ans);
    }
    int kthLargest(Node *root, int K)
    {
        int ans;
        int c=0;
        helper(root, K, ans);
        
        return ans;
    }
};
