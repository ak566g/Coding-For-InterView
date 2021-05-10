vector<vector<int>>ans;

void helper(Node *root, vector<int>temp){
    if(root==NULL){
        return;
    }
    
    temp.push_back(root->data);
    
    if(root->left==NULL && root->right==NULL){
        ans.push_back(temp);
    }
    else{
        helper(root->left, temp);
        helper(root->right, temp);
    }
} 
 
vector<vector<int>> Paths(Node* root)
{
    // Code here
    for(int i=0;i<ans.size();i++)
        ans[i].clear();
        
    ans.clear();
    
    vector<int>temp;
    helper(root, temp);
    
    return ans;
}