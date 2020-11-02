//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

class trieNode
{
    public:
    trieNode *left;
    trieNode *right;

    trieNode()
    {
        this->left=NULL;
        this->right=NULL;
    }

};

void insert(int n, trieNode *root)
{
    trieNode *curr = root;

    for(int i=31;i>=0;i--)
    {
        int b = (n>>i)&1;
        if(b==1)
        {
            if(curr->right==NULL)
            {
                trieNode *newnode = new trieNode();
                curr->right = newnode;
            }
            curr=curr->right;
        }
        else
        {
            if(curr->left==NULL)
            {
                trieNode *newnode = new trieNode();
                curr->left = newnode;
            }
            curr=curr->left;
        }   
    }
}


int findMaxXor(int *a, int n, trieNode *root)
{
    int maxAns= 0;

    for(int i = 0;i<n;i++)
    {
        int value = a[i];
        trieNode *curr = root;
        int currAns=0;
        for(int j=31;j>=0;j--)
        {
            int b = (value>>j)&1;

            if(b==0)
            {
                if(curr->right)
                {
                    curr=curr->right;
                    currAns+=pow(2,j);
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
                    curr=curr->left;
                    currAns+=pow(2,j);
                }
                else
                {
                    curr=curr->right;
                }
                
            }
        }

        maxAns = max(maxAns, currAns);
    }
    return maxAns;
}

int main(){

    int n;
    cin>>n;
    
    trieNode *trie = new trieNode();


    int *a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        insert(a[i], trie);
    }

    cout<<findMaxXor(a, n, trie);
}