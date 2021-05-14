
int distance(Node* root, int data){
    if(root==NULL){
        return -1;
    }
    
    if(root->data == data){
        return 0;
    }
    
    int leftAns = distance(root->left, data);
    int rightAns = distance(root->right, data);
    
    if(leftAns == -1 && rightAns == -1){
        return -1;
    }else if(leftAns == -1){
        return 1+rightAns;
    }
    
    return 1+leftAns;
}

Node* lca(Node* root, int a, int b){
    if(root==NULL){
        return root;
    }
    
    if(root->data == a || root->data == b){
        return root;
    }
    
    Node* left = lca(root->left, a, b);
    Node* right = lca(root->right, a, b);
    
    if(left && right){
        return root;
    }else if(left){
        return left;
    }
    return right;
}   

int findDist(Node* root, int a, int b) {
    // Your code here
    int da = distance(root, a);
    int db = distance(root, b);
    
    if(da == -1 || db == -1){
        return -1;
    }
    
    Node* ld = lca(root, a, b);
    int lcaDist = distance(root, ld->data);
    
    
    return da+db - 2*lcaDist;
}