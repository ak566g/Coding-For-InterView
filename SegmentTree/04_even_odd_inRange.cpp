//by Ankita Gupta


// Counting Even/Odd

// Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.
// He gives him an array of N natural numbers and asks him to solve the following queries:-
// Query 0 :- modify the element present at index i to x.
// Query 1:- count the number of even numbers in range l to r inclusive.
// Query 2:- count the number of odd numbers in range l to r inclusive.

#include<bits/stdc++.h>
using namespace std;

class Tree{
    public :
    int even;
    int odd;
};

void buildTree(int *a, int start, int end, Tree *tree, int ti)
{
    if(start==end)
    {
        if(a[start]%2==0)
        {
            tree[ti].even=1;
            tree[ti].odd=0;
        }
        else
        {
            tree[ti].even=0;
            tree[ti].odd=1;
        }
        
        return;
    }
    
    int mid = (start + end)/2;
    
    buildTree(a,start,mid,tree,2*ti);
    buildTree(a,mid+1,end,tree,2*ti+1);
    
    tree[ti].even = tree[2*ti].even + tree[2*ti+1].even;
    tree[ti].odd = tree[2*ti].odd + tree[2*ti+1].odd;
    
    return;
}


Tree queryTree(Tree *tree, int start, int end, int l, int r, int ti)
{
	if(r<start || l>end)
    {
        Tree ans;
        ans.even=0;
        ans.odd=0;
        
        return ans;
    }
    
    if(start>=l && end<=r)
    {
        return tree[ti];
    }
    
    int mid = (start + end)/2;
    
    Tree left= queryTree(tree, start, mid, l, r, 2*ti);
    Tree right= queryTree(tree, mid+1, end, l, r, 2*ti+1);
    
    Tree ans;
    ans.even=left.even+right.even;
    ans.odd=left.odd+right.odd;
    
    return ans;
}


void updateTree(Tree *tree, int ti ,int *a, int start , int end, int idx, int val)
{
    if(start==end)
    {
        a[idx]=val;
        if(val%2==0)
        {
            tree[ti].even=1;
            tree[ti].odd=0;
        }
        else
        {
            tree[ti].even=0;
            tree[ti].odd=1;
        }
        return;
    }
    
    int mid= (start + end)/2;
    
    if(mid<idx)
    {
        updateTree(tree, 2*ti+1, a, mid+1, end, idx, val);
    }
    else
    {
        updateTree(tree, 2*ti, a, start, mid, idx, val);
    }
    
    tree[ti].even = tree[2*ti].even + tree[2*ti+1].even;
    tree[ti].odd = tree[2*ti].odd + tree[2*ti+1].odd;
}

int main() {

    int n;
    cin>>n;
    
    int *a = new int[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    Tree *tree = new Tree[4*n];
    
    buildTree(a,0,n-1,tree,1);
    
    int q;
    cin>>q;
    while(q--)
    {
        int option;
        cin>>option;
        int x, y;
        cin>>x>>y;
        
        if(option==0)
        {
            updateTree(tree,1 ,a,0 ,n-1,x-1,y);
        }
        else if(option==1)
        {
            Tree ans=queryTree(tree,0,n-1, x-1, y-1, 1);
            cout<<ans.even<<"\n";
        }
        else if(option==2)
        {
            Tree ans=queryTree(tree,0,n-1, x-1, y-1, 1);
            cout<<ans.odd<<"\n";
        }
    }
	
}