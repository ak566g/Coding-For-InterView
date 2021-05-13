unordered_map<string, int>um;
bool ans = false;

string helper(Node *root){
    if(root==NULL){
        return "$";
    }
    
    string s= "";
    
    if(root->left==NULL && root->right==NULL){
        return to_string(root->data);
    }
    
    s += root->data;
    
    s = s + helper(root->left);
    s = s + helper(root->right);
    
    um[s]++;
    
    return s;
}

bool dupSub(Node *root)
{
    um.clear();
    helper(root);
    
    for (auto it:um){
        if(it.second>=2)
        return true;
    }
    
    return false; 
}