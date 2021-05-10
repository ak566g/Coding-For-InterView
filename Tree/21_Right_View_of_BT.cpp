class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    
    vector<int>ans;
    bool vis[100005];
    
    
    void helper(Node *root, int curL){
        if(root==NULL)
            return;
        
        if(vis[curL]==false){
            ans.push_back(root->data);
        }
        vis[curL]=true;    
        
        helper(root->right, curL+1);
        helper(root->left, curL+1);
    }
    
    vector<int> rightView(Node *root)
    {
       // Your Code here
       memset(vis, false, sizeof(vis));
       ans.clear();
       
       helper(root, 0);
       
       return ans;
    }
};
