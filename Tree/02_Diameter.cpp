
PAIR cal(Node *node){
    if(node==NULL)
    {
        PAIR P;
        P.height=0;
        P.diameter=0;
        return P;
    }
    
    PAIR P1=cal(node->left);
    PAIR P2= cal(node->right);
    
    PAIR P3;
    
    int h,d, lh=P1.height, ld=P1.diameter, rh=P2.height, rd=P2.diameter;
    
    h=1+max(lh,rh);
    d=max(lh+rh,max(ld,rd));
    
    P3.height=h;
    P3.diameter=d;
    
    return P3; 
}



int diameter(Node* node) {
    // Your code here
    
    PAIR P= cal(node);
    return P.diameter+1;

}

// Another Approach

class Solution {
public:
    
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        
        return 1+ max(height(root->left), height(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int leftD = diameterOfBinaryTree(root->left);
        int rightD = diameterOfBinaryTree(root->right);
        
        int cur = height(root->left) + height(root->right);
        
        return max(leftD, max(rightD, cur));
    }
};