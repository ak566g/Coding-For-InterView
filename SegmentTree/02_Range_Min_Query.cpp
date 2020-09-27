#include<bits/stdc++.h>
using namespace std;

void buildMinTree(int *a, int start , int end, int *tree, int treeIndex)
{
    if(start==end)
    {
     	tree[treeIndex]=a[start];
        return;
    }
    
    int mid = (start + end)/2;
    
    buildMinTree(a, start , mid, tree, 2*treeIndex);
    buildMinTree(a, mid+1, end, tree, 2*treeIndex+1);
    
    tree[treeIndex]= min(tree[treeIndex*2], tree[treeIndex*2+1]);
    
    return ;
}

void updateMinTree(int *a, int start, int end, int *tree, int treeIndex, int val, int idx)
{
    if(start==end)
    {
        tree[treeIndex]=val;
        a[idx]=val;
        return;
    }
    
    int mid=(start+end)/2;
    
    if(mid<idx)
    {
        updateMinTree(a,mid+1,end,tree,2*treeIndex+1, val, idx);
    }
    else
    {
        updateMinTree(a,start,mid,tree,2*treeIndex, val, idx);
    }
    
    tree[treeIndex]= min(tree[2*treeIndex],tree[2*treeIndex+1]);
    
    return;
}


int rangeMinQuery(int *tree, int start, int end, int treeIndex, int l, int r)
{
    if(l>end || r<start)
        return INT_MAX;
    
    if(start>=l && end<=r)
        return tree[treeIndex];
    
    int mid= (start+end)/2;
    
    int ans1= rangeMinQuery(tree, start, mid, 2*treeIndex,l,r);
    int ans2= rangeMinQuery(tree, mid+1, end, 2*treeIndex+1,l,r);
    
    return min(ans1,ans2);
}


int main() {
	
    int n,q;
    cin>>n>>q;
    
    int *a = new int [n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    int *tree= new int[4*n];
    
    buildMinTree(a,0,n-1,tree,1);
    
    while(q--)
    {
    	char c;
        cin>>c;
        
        if(c=='q')
        {
            int start, end;
            cin>>start>>end;
            start--;
            end--;
            cout<<rangeMinQuery(tree,0,n-1,1,start,end)<<"\n";
        }
        else
        {
            int idx, value;
            cin>>idx>>value;
            idx--;
            updateMinTree(a,0,n-1,tree,1,value,idx);
        }
    }
}