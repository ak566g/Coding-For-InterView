class Solution{
  public:
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(!root1 && !root2){
            return true;
        }
        
        if(!root1 || !root2){
            return false;
        }
        
        if(root1->data != root2->data){
            return false;
        }
        
        bool ans1 = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
        bool ans2 = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
        
        return ans1 || ans2;
    }
};