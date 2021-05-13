
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    if(iStart>iEnd){
        return NULL;
    }
    
    int lIndex = n+1;
    for(int i=iStart; i<=iEnd; i++){
        for(int j=0;j<n;j++){
            if(inorder[i]==levelOrder[j]){
                lIndex = min(lIndex, j);
            }
        }
    }
    
    Node *curNode = new Node(levelOrder[lIndex]);
    
    if(iStart==iEnd){
        return curNode;
    }
    
    int inIndex = -1;
    
    for(int i=iStart;  i<=iEnd; i++){
        if(inorder[i]==levelOrder[lIndex]){
            inIndex = i;
            break;
        }
    }
    
    Node* left = buildTree(inorder, levelOrder, iStart, inIndex-1, n);
    Node* right = buildTree(inorder, levelOrder, inIndex+1, iEnd, n);
    
    curNode->left = left;
    curNode->right = right;
    
    return curNode;
}