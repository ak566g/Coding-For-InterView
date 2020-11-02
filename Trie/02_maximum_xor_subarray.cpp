#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
    trieNode *left;
    trieNode *right;
    
    trieNode()
    {
        left=NULL;
        right=NULL;
    }
};


void insert(int n, trieNode *root)
{
    trieNode *curr = root;
    for(int i=31;i>=0;i--)
    {
        int b=(n>>i)&1;
        if(b==0)
        {
            if(curr->left==NULL)
            {
                curr->left = new trieNode();
            }
            curr=curr->left;
        }
        else
        {
            if(curr->right==NULL)
            {
                curr->right= new trieNode();
            }
            curr=curr->right;
        }
    }
}

int findMax(int n, trieNode *root)
{
    int maxVal=0;
    trieNode *curr = root;
    for(int i=31;i>=0;i--)
    {
        int b= (n>>i)&1;
        if(b==0)
        {
            if(curr->right)
            {
                maxVal += pow(2,i);
                curr=curr->right;
            }
            else
            {
                curr=curr->left;
            }
        }
        else
        {
            if(curr->left)
            {
                maxVal += pow(2,i);
                curr=curr->left;
            }
            else
            {
                curr=curr->right;
            }
        }
    }
    
    return maxVal;
}

int main() {

    int n;
    cin>>n;
    
    int *a= new int[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    trieNode *trie = new trieNode();
    int prefix_xor=0;
    insert(prefix_xor, trie);
    int maxAns=a[0];
    
    for(int i=0;i<n;i++)
    {
        prefix_xor ^= a[i];
        maxAns= max(maxAns, findMax(prefix_xor, trie));
        insert(prefix_xor, trie);
    }
    
    cout<<maxAns;
}