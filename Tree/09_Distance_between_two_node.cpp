int lca(Node *root, int a, int b){
    if(root==NULL){
        return -1;
    }
    
    if(root->data == a || root->data == b){
        return root->data;
    }
    
    int leftLCA = lca(root->left, a, b);
    int rightLCA = lca(root->right, a, b);
    
    if(leftLCA!=-1 && rightLCA!=-1){
        return root->data;
    }
    
    if(leftLCA==-1){
        return rightLCA;
    }
    return leftLCA;
}

int distance(Node *root, int val){
    if(root==NULL){
        return -1;
    }
    
    if(root->data==val){
        return 0;
    }
    
    int leftD = distance(root->left, val);
    int rightD = distance(root->right, val);
    
    if(leftD!=-1){
        return 1+leftD;
    }
    
    if(rightD!=-1){
        return 1+rightD;
    }
    
    return -1;
}
   
int findDist(Node* root, int a, int b) {
    // Your code here
    
    int lcaD = lca(root, a, b);
    int lD = distance(root, lcaD);
    int aD = distance(root, a);
    int bD = distance(root, b);
    
    return aD+bD-2*lD;
}