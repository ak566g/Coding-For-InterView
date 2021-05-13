vector<int>ans;

void printLeft(Node *root){
    
    if(root==NULL)
    return;
    
    if(root->left){
        ans.push_back(root->data);
        printLeft(root->left);
    }else if(root->right){
        ans.push_back(root->data);
        printLeft(root->right);
    }
}


void printRight(Node *root){
    if(root==NULL)
    return;
    
    if(root->right){
        printRight(root->right);
        ans.push_back(root->data);
    }else if(root->left){
        printRight(root->left);
        ans.push_back(root->data);
    }
}


void printLeaf(Node *root){
    if(root==NULL){
        return;
    }

    printLeaf(root->left);
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    printLeaf(root->right);
}
vector <int> printBoundary(Node *root)
{
     ans.clear();
     
     ans.push_back(root->data);
     printLeft(root->left);
     printLeaf(root);
     printRight(root->right);
     
     return ans;
}