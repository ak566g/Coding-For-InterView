//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;

class trieNode{
    public:
    trieNode *left;
    trieNode *right;
    int lc;
    int rc;

    trieNode()
    {
        left = NULL;
        right= NULL;
        lc=0;
        rc=0;
    }
};

void insert(trieNode *root, int n)
{
    trieNode *curr=root;
    for(int i=31;i>=0;i--){
        int b=(n>>i)&1;

        if(b==0)
        {
            curr->lc++;
            if(curr->left == NULL)
            {
                curr->left = new trieNode();
            }
            curr = curr->left;
        }

        else if(b==1)
        {
            curr->rc++;
            if(curr->right == NULL)
            {
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
}

// ll count_leaf_node(trieNode *root)
// {
//     if(root==NULL)
//     return 0;
    
//     if(root->left == NULL && root->right==NULL)
//     return 1;

//     return count_leaf_node(root->left)+count_leaf_node(root->right);
// }

ll xor_count(trieNode *root, int n, int k)
{

    if(root==NULL)
    return 0;

    ll count=0;
    trieNode *curr=root;

    for(int i=31;i>=0;i--)
    {
        int bn= (n>>i)&1;
        int bk= (k>>i)&1;
        if(bn==0 && bk==0)
        {
            if(curr->left==NULL)
                return count;
            curr=curr->left;
        }
        else if(bn==1 && bk==0)
        {
            if(curr->right==NULL)
                return count;
            curr=curr->right;
        }
        else if(bn==0 && bk==1)
        {
            count+=curr->lc;
            if(curr->right==NULL)
                return count;
            curr=curr->right;
        }
        else if(bn==1 && bk==1)
        {
            count+= curr->rc;
            if(curr->left==NULL)
                return count;
            curr= curr->left;
        }
    }

    return count;
}

ll xor_subarray_count(int *a, int n, int k)
{
    trieNode *trie = new trieNode();
    insert(trie, 0);
    int xor_till_i=0;
    ll count=0;
    for(int i=0;i<n;i++)
    {
        xor_till_i = xor_till_i^a[i];
        count+= xor_count(trie, xor_till_i, k);
        insert(trie, xor_till_i);
    }

    return count;
}

int main(){

    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        int *a = new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        cout<<xor_subarray_count(a, n, k);
        cout<<"\n";
    }
}