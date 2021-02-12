#include<bits/stdc++.h>
#define ll long long
using namespace std;

class TreeNode{
    public:
        ll data;
        TreeNode *left;
        TreeNode *right;


        TreeNode* insert(TreeNode *root, ll data){
            if(root==NULL){
                TreeNode *node = new TreeNode(data);
                return node;
            }
            if(data > root->data){
                root->right = insert(root->right, data);
            }
            else{
                root->left = insert(root->left, data);
            }

            return root;
        }

        bool find(TreeNode *root, ll elem)
        {
            if(root==NULL){
                return false;
            }

            if(root->data == elem){
                return true;
            }

            if(root->data>elem)
                return find(root->left, elem);
            else
                return find(root->right, elem);
        }
        
        TreeNode(){
            data = -1;
            left = NULL;
            right = NULL;
        }

        TreeNode(ll data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};
int main()
{
    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;
        TreeNode *root = NULL;
        TreeNode tree;
        for(int i=0; i<n; i++){
            ll x;
            cin>>x;
            root=tree.insert(root, x);
        }
        

        for(int i=0;i<m;i++){
            ll x;
            cin>>x;

            bool flag= tree.find(root, x);

            if(flag){
                cout<<"YES";
            }
            else{
                cout<<"NO";
                tree.insert(root, x);
            }
            cout<<"\n";
        }
    }
}