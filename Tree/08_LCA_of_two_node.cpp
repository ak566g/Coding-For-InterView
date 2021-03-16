class Solution
{
    public:
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       
       if(root==NULL){
           return NULL;
       }
       
       if(root->data == n1 || root->data == n2){
           return root;
       }
       
       Node *leftL = lca(root->left, n1, n2);
       Node *rightL = lca(root->right, n1, n2);
       
       if(leftL&&rightL){
           return root;
       }
       
       if(leftL){
           return leftL;
       }
       
       return rightL;
    }
};