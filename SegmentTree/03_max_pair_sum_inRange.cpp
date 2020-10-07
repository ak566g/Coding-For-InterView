#include<bits/stdc++.h>
using namespace std;

class Tree{
    public:
    int m;
    int sm;
};

Tree compare(Tree t1, Tree t2)
{
    Tree ans;
    ans.m = max(t1.m, t2.m);
    ans.sm= min(max(t1.m,t2.sm), max(t2.m,t1.sm));
    
    return ans;
}

void buildTree(int *a, Tree *tree, int start, int end, int ti)
{
    if(start==end)
    {
        tree[ti].m=a[start];
        tree[ti].sm=INT_MIN;
        
        return;
    }
    
    int mid = (start + end)/2;
    
    buildTree(a,tree, start, mid, 2*ti);
    buildTree(a,tree, mid+1, end, 2*ti+1);
    
    Tree left = tree[2*ti];
    Tree right= tree[2*ti+1];
    
    tree[ti]=compare(left,right);
    
    return;
}


Tree queryTree(Tree *tree, int start, int end, int l, int r, int ti)
{
    if(start>end)
    {
        return {INT_MIN, INT_MIN};
    }
    
    if(start>r || end<l)
    {
        return {INT_MIN, INT_MIN};
    }
    
    if(start>=l && end<=r)
    {
        return tree[ti];
    }
    
    int mid = (start+end)/2;
    
    Tree left = queryTree(tree, start, mid, l, r, 2*ti);
    Tree right = queryTree(tree, mid+1, end, l, r, 2*ti+1);
    
    Tree ans= compare(left, right);
    return ans;
}

void updateTree(Tree *tree, int start, int end, int idx, int val, int ti)
{
    if(start==end)
    {
        tree[ti].m=val;
        return;
    }
    
    int mid= (start+end)/2;
    
    if(mid<idx)
    {
        updateTree(tree, mid+1, end, idx, val, 2*ti+1);
    }
    else
    {
        updateTree(tree, start, mid, idx, val, 2*ti);
    }
    
    tree[ti] = compare(tree[2*ti], tree[2*ti+1]);
    
    return;
}

int main() {
    int n;
    cin>>n;
    
    int *a= new int[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    Tree *tree = new Tree[4*n];
    
    buildTree(a, tree, 0, n-1, 1);
    
    int q;
    cin>>q;
    
    while(q--)
    {
        char option;
        cin>>option;
        
        if(option=='Q')
        {
            int l, r;
            cin>>l>>r;
            Tree ans=queryTree(tree, 0, n-1, l-1, r-1, 1);
            cout<<ans.m+ans.sm<<"\n";
        }
        else if(option=='U')
        {
            int idx, val;
            cin>>idx>>val;
            updateTree(tree,0,n-1,idx-1,val,1);
        }
    }
    
    
}