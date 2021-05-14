bool helper(Node *root, int l, int h){
    if(root==NULL){
        return false;
    }
    
    if(l==h){
        return true;
    }
    
    return helper(root->left, l, root->data-1)||
        helper(root->right, root->data+1, h);
}

bool isDeadEnd(Node *root)
{
    return helper(root, 1, INT_MAX);
}