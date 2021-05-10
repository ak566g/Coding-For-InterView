vector<int>ans;
int vis[1005];

void helper(Node *root, int curL){
    if(root==NULL){
        return;
    }
    
    if(vis[curL]==false){
        ans.push_back(root->data);
    }
    
    vis[curL]=true;
    
    helper(root->left, curL+1);
    helper(root->right, curL+1);
}

vector<int> leftView(Node *root)
{
   ans.clear();
   memset(vis, false, sizeof(vis));

   helper(root, 0);
   
   return ans;
}
