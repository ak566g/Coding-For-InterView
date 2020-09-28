#include<bits/stdc++.h>
using namespace std;

class Tree{
    public :
    int m;	//Maximum Element
    int sm;	//Second Maximum Element
};

Tree queryTree(Tree *tree, int start, int end, int l, int r, int treeIndex)
{
    if(start>r || end<l)
    {
        Tree ans;
        ans.m=INT_MIN;
        ans.sm=INT_MIN;
        return ans;
    }
    
    if(start>=l && end<=r)
    {
        return tree[treeIndex];
    }
    
    int mid=(start + end )/2;
    
    Tree ans1 = queryTree(tree, start, mid, l, r, 2*treeIndex);
    Tree ans2 = queryTree(tree, mid+1, end, l, r, 2*treeIndex+1);
    
    Tree ans;
    ans.m= max(ans1.m, ans2.m);
    ans.sm = min(max(ans1.m,ans2.sm),max(ans1.sm,ans2.m));
    
    return ans;
}

void buildTree(int *a, int start, int end, Tree *tree, int treeIndex)
{
    if(start==end)
    {
        tree[treeIndex].m=a[start];
        tree[treeIndex].sm=INT_MIN;
        return;
    }
    
    int mid= (start+end)/2;
    
    buildTree(a,start,mid,tree,2*treeIndex);
    buildTree(a,mid+1,end,tree,2*treeIndex+1);
    
    Tree left = tree[2*treeIndex];
    Tree right = tree[2*treeIndex+1];
    
    tree[treeIndex].m= max(left.m, right.m);
    tree[treeIndex].sm= min(max(left.m,right.sm),max(left.sm,right.m));
    
   	 
    return;
    
}

void updateTree(int *a, Tree *tree, int start, int end, int treeIndex, int value, int idx)
{
    if(start==end)
    {
        a[idx]=value;
        tree[treeIndex].m=value;
    	return;
    }
    
    int mid = (start+end)/2;
    
    if(mid<idx)
    {
        updateTree(a,tree,mid+1,end,2*treeIndex+1,value,idx);
    }
    else
    {
        updateTree(a,tree,start,mid,2*treeIndex,value,idx);
    }
    
    Tree left= tree[2*treeIndex];
    Tree right= tree[2*treeIndex+1];
    
    tree[treeIndex].m= max(left.m,right.m);
    tree[treeIndex].sm= min(max(left.m,right.sm),max(left.sm,right.m));
    return;
}

int main() {

    int n;
    cin>>n;
   
    int *a = new int [n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];
    
  	Tree *tree = new Tree[4*n];
    
    buildTree(a,0,n-1,tree,1);
    
    int q;
    cin>>q;
    
    while(q--)
    {
        char c;
        cin>>c;
        
        if(c=='Q')
        {
            int start, end;
            cin>>start>>end;
            start--;
            end--;
            Tree ans= queryTree(tree,0,n-1,start,end,1);
            //cout<<ans.m<<" "<<ans.sm<<"\n";
            cout<<ans.m+ans.sm<<"\n";
        }
        else
        {
            int index, value;
            cin>>index>>value;
            index--;
            
            updateTree(a,tree,0,n-1,1,value,index);
        }
    }
    
}